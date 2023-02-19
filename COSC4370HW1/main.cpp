#include <iostream>
#include "BMP.h"
#include <cmath>


//used this website for reference: https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/

void midPointEllipse(BMP& bmpNew, long x_center, long y_center, long x_radius, long y_radius);

void plotPoints(BMP& bmpNew, long x_radius, long y_radius, long x_center, long y_center);


int main(){
  
  BMP bmpNew(1600, 2000, false);

  //we set our center coordinates here
  long x_center = 800;
  long y_center = 1000;
  
  //radius values of the ellipse we are drawing
  long x_radius = 6*sqrt(64*64);
  long y_radius = 12*sqrt(64*64); 
  
  midPointEllipse(bmpNew, x_center, y_center, x_radius, y_radius);


  //writes our new ellipse to image
  bmpNew.write("output.bmp");
  
  return 0;

}

void midPointEllipse(BMP& bmpNew, long x_center, long y_center, long x_radius, long y_radius){
 
  
  long x = 0;
  long y = y_radius;

  long stop_x = 2 * y_radius * y_radius * x;
  long stop_y = 2 * x_radius * x_radius * y;

//decision parameter for quadrant 1
  long quad1 = y_radius*y_radius - x_radius*x_radius*y_radius + 0.25 * x_radius*x_radius; 

      // Checking and updating value of
      // decision parameter based on algorithm
     while(stop_x < stop_y){
       //plots our points
        plotPoints(bmpNew, x_center, y_center, x, y);
        if (quad1 < 0){
            x++;
            stop_x += (2 * y_radius * y_radius);
            quad1 += stop_x + y_radius*y_radius;
        }
        else{
            x++;
            y--;
            stop_x += (2 * y_radius * y_radius);
            stop_y -= (2 * x_radius * x_radius);
            quad1 += stop_x - stop_y + y_radius*y_radius;
        }
    }

  //decision paramter for quadrant 2
    long quad2 = y_radius * y_radius * (x + 0.5) * (x + 0.5) +
          x_radius * x_radius * (y - 1) * (y - 1) - x_radius * x_radius * y_radius * y_radius;
  
    while(y > 0){
      //plots our points
        plotPoints(bmpNew,  x_center, y_center, x, y);
        // Checking and updating value of
        // decision parameter based on algorithm
        if (quad2 > 0){
            y--;
            stop_y -= 2 * x_radius * x_radius;
            quad2 += x_radius * x_radius - stop_y;
        }
        else{
            x++;
            y--;
            stop_x +=  2 * y_radius * y_radius;
            stop_y -= 2 * x_radius * x_radius;
            quad2 += stop_x - stop_y + x_radius * x_radius;
        }
    }

  
}

void plotPoints(BMP& bmpNew,long x_center, long y_center, long x_dist, long y_dist){

  //plots point in quadrant I
  bmpNew.set_pixel(x_center+x_dist, y_center+y_dist, 255, 255, 255, 0);
  //plots point in quadrant II
  bmpNew.set_pixel(x_center-x_dist, y_center+y_dist, 255, 255, 255, 0);
  
}
