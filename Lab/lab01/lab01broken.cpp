//Name: COLE, DALTON
//Class and Section: CS 54, Section 3C
//Date: 8-27-2013
//Description: Take the width and length of a rectangle fron the user and
//	outputs the area.

#include <iostream>
using namespace std;

int main()
{
  //Declarations
  float length, width, area;
  
  //Prompt user for length
  cout << "Please enter the length of the rectangle: " << endl;
  
  cin >> length;
  
  //Prompt user for width
  cout << "Please enter the width of the rectangle: " <<  endl;
  
  cin >> width;
  
  //Calculate area
  area = length * width;
  
  //Output results
  cout << "You entered length: " << length << " and width: " ;
  cout << width << " which results in area: " << area << ".";
  cout << endl;
  
  //end program
  return 0;
}

