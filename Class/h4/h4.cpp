//Programer: Dalton Cole
//Class and Section: CS53, 1A
//Date: 9/19/13
//Description: homework 4, this program uses the user's bank account to
//             transfer funds to a slot machine, then allows the user
//	       to play the slots.

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
  
  const short MIN_START = 200;
  const short MAX_START = 1000;
  const short MIN_SPIN = 1;
  const short MAX_SPIN = 4;
  const short MAX_WINNINGS = 30;
  const short MIN_WINNINGS = 1;
  const short LOSE = 5;
  
  char choice, char1, char2, char3;
  short rand1, rand2, rand3, pull_times;
  float game_balance = 0, bank_balance, transfer, game_winnings = 0;
  bool start1; //user must start with 1
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  //sets random generater based on time
  srand(time(NULL));

  //creates bank balance
  bank_balance = ((rand() % (MAX_START - MIN_START + 1)) + MIN_START);
  
  do
  {
      cout << "      OPTIONS" << endl;
      cout << "      -------" << endl;
      cout << "1. Check Bankk\xa9 balance" << endl; 
      cout << "2. Transfer funds to game" << endl;
      cout << "3. Play" << endl;
      cout << "4. Leave (cash out)" << endl;
      cin >> choice;
    
    if (choice == '1')
      start1 = true;  
            
    if (start1 == true)
    {
      switch (choice)
      {
      //displays user's current bank balance
        case '1': 
          cout << "Your Bankk\xa9 balance is: $" << bank_balance << endl;
          break;
        //asks user to transfer funds
        case '2':
          {
            cout << "How much money would you like to transfer from ";
            cout << "your bank account into the game?" << endl;
            cin >> transfer;
          
            if (transfer > bank_balance)
              cout << "Insufficient funds" << endl;
            else
            {
              game_balance = game_balance + transfer;
              bank_balance = bank_balance - transfer;
            
              //displays game balance
              cout << "You now have $" << game_balance << " to play with.";
            }                   
          }
          break;
        case '3':
          {
            if (game_balance < 5)
              cout << "Insufficient funds for game." << endl;
            else
            {
              cout << "How many times would you like to play?" << endl;
              cin >> pull_times;
             
              if (game_balance < (pull_times * 5))
              {
                cout << "Insufficient funds for game." << endl;
              }
              else
              {
                //executes the number of pulls that the user imputed
                for (int i=0; pull_times > i; i++)
                {
                  //randomly generates 3 numbers
                  rand1 = ((rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN);
                  rand2 = ((rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN);
                  rand3 = ((rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN);
              
                  //changes numbers to letters
                  switch (rand1)
                  {
                    case 1:
                      char1 = 'a';
                      break;
                    case 2:
                      char1 = 'b';
                      break;
                    case 3:
                      char1 = 'c';
                      break;
                    case 4:
                      char1 = 'd';
                      break;
                  }
                  switch (rand2)
                  {
                    case 1:
                      char2 = 'a';
                      break;
                    case 2:
                      char2 = 'b';
                      break;
                    case 3:
                      char2 = 'c';
                      break;
                    case 4:
                      char2 = 'd';
                      break;
                  }
                  switch (rand3)
                  {
                    case 1:
                      char3 = 'a';
                      break;
                    case 2:
                      char3 = 'b';
                      break;
                    case 3:
                      char3 = 'c';
                      break;
                    case 4:
                      char3 = 'd';
                      break;
                  }
                
                  //prints spins
                  cout << "Your spins are: " << char1 << " " << char2;
                  cout << " " << char3 << endl;
           
                  //caculate and display winnings
                  if (rand1 == rand2 && rand1 == rand3)
                  {
                    game_balance = game_balance + MAX_WINNINGS;
                    game_winnings = game_winnings + MAX_WINNINGS;
                  }
                  else if (rand1 == rand2 || rand1 == rand3 || rand2 == rand3)
                  {
                    game_balance = game_balance + MIN_WINNINGS;
                    game_winnings = game_winnings + MIN_WINNINGS;
                  }
                  else
                  {
                    game_balance = game_balance - LOSE;
                    game_winnings = game_winnings - LOSE;
                  }
                }
              }
              cout << "You won " << game_winnings << " dollars!" << endl;    
              cout << "Your game balance is now $" << game_balance << endl;
               
              // set game winnings back to 0
              game_winnings = 0;
            }  
          }
          break;
      }
    }
    else
      cout << "You must check you Bankk\xa9 balance before you proceed." << endl;
    
    //if user has less than 5 dollars, they get kicked out
    if (game_balance <5 && bank_balance <5)
      {
      choice = 4;
      cout << "You do not have enough funds in your bank or game to ";
      cout << "play again." << endl << "Good bye." << endl;
      }
  } while (choice != '4');

  //Displays balances
  cout << "You have $" << game_balance << " left in the game " << endl;
  cout << "and you have $" << bank_balance << " left in the BanKK\xa9 " << endl;
  
  //end program
  return 0;
}
