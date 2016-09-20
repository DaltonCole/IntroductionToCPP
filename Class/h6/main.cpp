//Programer: Dalton Cole
//Class and Section: cs53, 1A
//Date: 10/6/13
//Description: homework 6 main

#include "h6.h"

int main()
{
  float bank_balance, game_balance = 0;
  short choice;
  bool First1 = false; //menu option 1 must be chosen first
 
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  //sets random generator based on time
  srand(time(NULL)); 
  
  //sets bank_balance
  bank_balance = ((rand() % (MAX_START - MIN_START + 1)) + MIN_START);
  
  Greetings();
      
  do
  { 
    choice = Menu();
    
    if (choice == 1 || choice == 4)
      First1 = true;
   
    //seperates based on user's menu choice 
    if (First1 == true)
    {
      switch (choice)
      {  
        case 1:
        {
          cout << "Your bankk\xa9 balance is: $" << bank_balance << endl;
          cout << "Your current game_balance is: $" << game_balance << endl;
        }
          break;
        case 2:
          game_balance = Option_two(bank_balance, game_balance);
          break;
        case 3:
          game_balance = Option_three(game_balance);
          break;   
      }
    }
    else
      cout << "You must pick option 1 first" << endl;
  
  }while (choice != 4);

  Goodbye (game_balance, bank_balance);

  return 0;
}
