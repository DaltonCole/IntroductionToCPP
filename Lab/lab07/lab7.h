//Name: COLE, DALTON
//Class and Section: cs54, C
//Date: 10/8/13
//Description: User imputes a num between 0-255 for blue, red, and
//	green, and outputes the grayscale for this

#ifndef rgd_j
#define rgd_h

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//structs
struct Pixel
{
  float m_red;
  float m_green;
  float m_blue;
};

//templates

//Des: This funtion takes the user imputed RGB colors and outputes a gray 
//	scale number
//Pre: the type of object sent to this function must be a user defined type
//Post: returns a grayscale value that can be of T type
template <typename T>
T rgbToGray(const T red, const T green, const T blue)
{
  return ((.2126 * red) + (.7152 * green) + (.0722 * blue));
}

//Functions

//Des: Asks the user if they wish to enter another RGB value to turn into
//	 Gray Scale
//Pre: none
//Post: returns the user imputed response of y or n to contiue
unsigned char rgbToGray (const Pixel p);

//Des  Outputes to the screen the values of the user imputed RGB and the
//	correlated Gray Scale value
//Pre: none
//Post: prints the value of RGB and Gray scale
void output (const Pixel p, const unsigned char grayValue);

//Des: User inputs the value of the RGB colors and returns them in a Pixel
//Pre: None
//Post: Returns the Three user imputed values in the Pixel struct
Pixel getPixel();

//Des: will randomly generate a random hue and print it 17 times
//	, the hue will have one 0 and one 255 rgb
//Pre: none
//Post: print 17 random hues that have one 0 and one 255 rgb
void randHue();


#endif
