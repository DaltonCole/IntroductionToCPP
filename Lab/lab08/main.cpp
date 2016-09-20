//Name: COLE, DALTON
//Section and Class: CS54, C
//Date: 10/15/13
//Description: main.cpp for lab08

#include "lab08.h"

int main()
{  
  //set rand to time
  srand(time(NULL));

  float f_org[SIZE]; //organize
  int i_org[SIZE];
  
  //randomly assigns arrays
  float_rand(f_org);
  
  int_rand(i_org);
  
  //sorts arrays
  Sort(f_org);
  
  Sort(i_org);

  //Prints all of the integers
  cout << "Integers: " << endl;
  for (int i = 0; i <= (SIZE - 1); i++)
  {
    cout << i_org[i];
    
    if (i != (SIZE-1))
    {
      cout << ", ";
    }
    else
      cout << endl;
  }
  //Prints all of the floats
  cout << "Floats: " << endl;
  for (int i = 0; i <= (SIZE - 1); i++)
  {
    cout << f_org[i];
    
    if (i != (SIZE-1))
    {
      cout << ", ";
    }
    else
      cout <<  endl;
  }

  return 0;
}
