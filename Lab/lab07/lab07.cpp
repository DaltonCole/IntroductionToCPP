//Name: COLE, DALTON
//Section and Class: CS54, C
//Date: 10/8/13
//Description: Lab07

#include "lab7.h"

unsigned char rgbToGray(const Pixel p)
{  
  char again;
  float red, green, blue;
  char grayValue;
  
  red = p.m_red;
  green = p.m_green;
  blue = p.m_blue;
  
  grayValue = rgbToGray(red, green, blue);
  
  output(p, grayValue);
  
  cout << "Enter another pixel? (y/n): ";
  cin >> again;
  
  return again;
}

void output(const Pixel p, const unsigned char grayValue)
{
  cout << "<" << p.m_red << "," << p.m_green << "," << p.m_blue << "> -> ";
  cout << static_cast<int>(grayValue) << endl;;
  
  return;
}


Pixel getPixel()
{
  Pixel p;
  
  cout << "Please enter a pixel: " << endl;
 
  cout << "Red: ";
  cin >> p.m_red;
  cout << "Green: ";
  cin >> p.m_green;
  cout << "Blue: ";
  cin >> p.m_blue;
  
  return p;
} 


void randHue();
{
  for (int i=0; i<17; i++)
  {
    
  }

  return;
}
