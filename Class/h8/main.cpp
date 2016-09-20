//Programmer: Dalton Cole
//Class and Section: 53, A
//Date: 10/28/13
//Description: Homework 8 Main. This program wil make Mo sound smart by
//making
//       five different fables with his own personal touch
//       (change words in a pre-existing fable.)

#include "fable.h"

int main()
{
  char ready;


  //set rand to time
  srand(time(NULL));

 
  //prompts to see if Moe wants to make a fable
  cout << "So, Moe, are you ready to create a fable? (y/n)" << endl;
  cin >> ready;
         
  if (ready != 'n')
  {
    do
    {
      printfable();  
   
    cout << endl << "Moe, would you like to create another fable? (y/n)";
    cout << endl;
    cin >> ready; 
    }while(ready != 'n');
  }




  return 0;
}
