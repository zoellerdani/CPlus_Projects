//Adapted from GeeksforGeeks

#include "image.h"
#include <iostream>

using namespace std;

void drawFractals(float left, float top, float xside, float yside,  int depth, const char* fileName){//will need parameters
    float xscale, yscale; //Scale of the image in x and y direction
    float zx, zy; //same as below but for diff value
    float cx, cy; //I believe that this is storing values needed for mandelbrot's eq
    float tempx; //needed for the mandelbrot's eq
    int x, y; //iterators for image pixels
    int maxx, maxy, count; //maximum values for x and y pixels
    
    maxx = 900;
  
    maxy = 900;
  
    // setting up the xscale and yscale
    xscale = xside / maxx;
    yscale = yside / maxy;
  
    // creating the image
    Image frac_img(maxx, maxy);
  
    // scanning every point in that rectangular area.
    // Each point represents a Complex number (x + yi).
    // Iterate that complex number
    for (y = 1; y <= maxy - 1; y++) {
        for (x = 1; x <= maxx - 1; x++)
        {
            // c_real
            cx = x * xscale + left;
  
            // c_imaginary
            cy = y * yscale + top;
  
            // z_real
            zx = 0;
  
            // z_imaginary
            zy = 0;
            count = 0;
  
             // Calculate whether c(c_real + c_imaginary) belongs
            // to the Mandelbrot set or not and draw a pixel
            // at coordinates (x, y) accordingly
            // If you reach the Maximum number of iterations
            // and If the distance from the origin is
            // greater than 2 exit the loop
            while ((zx * zx + zy * zy < 4) && (count < depth))
            {
                // Calculate Mandelbrot function
                // z = z*z + c where z is a complex number
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real
                tempx = zx * zx - zy * zy + cx;
  
                // 2*z_real*z_imaginary + c_imaginary
                zy = 2 * zx * zy + cy;
  
                // Updating z_real = tempx
                zx = tempx;
  
                // Increment count
                count = count + 1;
            }
  
            // To display the created fractal
            frac_img.set(x, y, count);
        }
    }
    frac_img.write(fileName);
    return;
}
  



int main(int argc, char **argv){
    
    // setting the left, top, xside and yside
    // for the screen and image to be displayed
    float left = atof(argv[2]);
    float top = atof(argv[3]);
    float xside = atof(argv[4]);
    float yside = atof(argv[4]);
  
    
    if(argc != 6){
        std::cout << "Usage: ./parallel iterations left top scale ../outputFileName.png" << std::endl;
    }
    else{
        // Function calling
        
        drawFractals(left, top, xside, yside, atoi(argv[1]), argv[5]);
    }
  
    
  
    return 0;
}
