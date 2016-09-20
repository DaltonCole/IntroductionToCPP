//Name: COLE, DALTON
//Section and Class: CS54, C
//Date: 10/8/13
//Description: lab07 main

#include "lab7.h"

int main()
{

  Pixel p;
  char again;
  
  do
  {
    p = getPixel();
    again = rgbToGray(p);
  
  }while (again != 'n');
  
  randHue();
  
  return 0;  
}
