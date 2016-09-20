//Name: COLE, DALTON
//Class and Section: cs54, C
//Date: 11/12/2013
//Description: Lab12, main file

#include "compound.h"

int main()
{
  Compound one, two, three, four;
  int mult_fact;

  cout << "Empty Compound: ";
  cout << one;
  cout << endl;
  
  cout << "Compound 1: ";  
  cin >> two;
  cout << "You entered: ";
  cout << two;
  cout << endl;
  
  cout << "Compound 2: ";
  cin >> three;
  cout << "You entered: ";
  cout << three;
  cout << endl;
  
  cout << "Result: ";
  four = two + three;
  cout << four;
  cout << endl;  
  cout << "Please enter multiplication factor: ";
  cin >> mult_fact;
  cout << endl;
  
  four = four * mult_fact;
  
  cout << "Result: ";
  cout << four;

  return 0;
}
