//Name: COLE, DALTON
//Class and section: CS54, C
//Date: 10/29/13
//Description: Lab10 function file

#include "lab10.h"

void decode(ifstream & input, ofstream & output, ofstream & submitOutput)
{
  char c;
  int i = 1;
  
  //tells the user that somethins is happening  
  cout << "Processing..." << endl;
  
  while(input.good())
  {
    input.get(c);
    
    //changes characters by 13
    if (c >= 110 && c <= 122)
      c -= 13;
    else if (c < 110 && c >= 97) 
      c +=13;
   
    
    
    output << c;
    
    //output the first 500 characters to submitOutput file
    if (i < 500)
      submitOutput << c;
    i++;
    
  }
  //one char is equal to 1 byte so...
  cout << "The file size of decode.output is: " << i/1000 << " kilo bytes.";
  cout << endl;


  return;
}


