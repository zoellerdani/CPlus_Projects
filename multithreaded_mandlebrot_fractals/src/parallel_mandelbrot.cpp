#include "image.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void drawFractals(float left, float top, float xside, float yside,  int depth, const char* fileName){//will need parameters
    float x_scale;
    float y_scale;
    float z_real;
    float z_imaginary;
    float c_real;
    float c_imaginary;
    float temp;
    int x_max = 900;
    int y_max = 900;
    int count;

    x_scale = xside / x_max;
    y_scale = yside / y_max;

    Image frac_img(x_max, y_max);
  
    #pragma omp parallel for
    for (int i = 1; i <= y_max - 1; i++) {
        for (int j = 1; j <= x_max - 1; j++)
        {
            c_real = j * x_scale + left;
            c_imaginary = i * y_scale + top;

            z_real = 0;
            z_imaginary = 0;

            count = 0;

            while ((z_real * z_real + z_imaginary * z_imaginary < 4) && (count < depth))
            {
                temp = z_real * z_real - z_imaginary * z_imaginary + c_real;
                z_imaginary = 2 * z_real * z_imaginary + c_imaginary;
                z_real = temp;
                count++;
            }

            frac_img.set(j, i, count);
        }
    }

    frac_img.write(fileName);
}

int main(int argc, char **argv){
    float left = atof(argv[2]);
    float top = atof(argv[3]);
    float xside = atof(argv[4]);
    float yside = atof(argv[4]);
  
    if(argc != 6){
        std::cout << "Usage: ./parallel iterations left top scale ../outputFileName.png" << std::endl;
    }
    else{
        drawFractals(left, top, xside, yside, atoi(argv[1]), argv[5]);
    }
  
    return 0;
}
