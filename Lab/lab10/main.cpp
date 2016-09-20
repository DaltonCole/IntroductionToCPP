//Name: COLE, DALTON
//Class and section: CS54, C
//Date: 10/29/13
//Description: Lab10 header

//Title and Author of book: Moby Dick by Herman Melville

#include "lab10.h"

int main()
{
  
  ifstream input("encoded.input");
  ofstream output("decoded.output");
  ofstream submitOutput("message.txt");
 
  //if file was not found, tell user 
  if(!input.good())
    cerr << "File not found!" << endl;
  
  decode(input, output, submitOutput);
  
  //closes streams
  input.close();
  output.close();
  submitOutput.close();
  
  //informs user that the progress is finished
  cout << "Done!" << endl;
  
  return 0;
}
