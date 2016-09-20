//Programer: Dalton Cole
//Class and Section: cs53, 1A
//Date: 10/6/13
//Description: Homework 6 function file

#include "h6.h"

void Greetings()
{
  cout << "Welcome Valued Custumer to the slot machine with the best odds";
  cout << " EVER!!!" << endl;
          
  return;
}

void Goodbye(const float game_balance, const float bank_balance)
{ 
  //displays game and bank balances
  cout << "Well done custumer!" << endl;
  cout << "You have $" << bank_balance << " left in the bank and" << endl;
  cout << "You have $" << game_balance << " left in the game!" << endl;   

  return;
}

short Menu()
{
  short choice;
  
  //user has to select a valid menu option
  do
  {
    //outputs the menu to user
    cout << "        OPTIONS" << endl;
    cout << "        -------" << endl;
    cout << "1. Check Bankk\xa9 balance" << endl;
    cout << "2. Transfer funds to game" << endl;
    cout << "3. Play" << endl;
    cout << "4. Leave (cash out)" << endl;
    cin >> choice;
  }while (choice != 1 && choice !=2 && choice !=3 && choice !=4);
  
  return choice;

}

Spin RandSpin()
{
  short rand1, rand2, rand3;
  Spin spin1;
  
  //gives a rand value for spin
  rand1 = ((rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN);
  rand2 = ((rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN);
  rand3 = ((rand() % (MAX_SPIN - MIN_SPIN + 1)) + MIN_SPIN);

  spin1 = Num_to_Letter(rand1, rand2, rand3);

  return spin1;
}

Spin Num_to_Letter(const short rand1, const short rand2, const short rand3)
{  
  Spin spin1;

  //changes value to corresponding char to spin1
  switch (rand1)
  {
    case 1:
      spin1.m_rand1 = 'a';
      break;
    case 2:
      spin1.m_rand1 = 'b';
      break;
    case 3:
      spin1.m_rand1 = 'c';
      break;
    case 4:
      spin1.m_rand1 = 'd';
      break;
  }
  switch (rand2)
  {                                          
    case 1:
      spin1.m_rand2 = 'a';                                                                                                                        
      break;
    case 2: 
      spin1.m_rand2 = 'b';                                                                                                                        
      break;
    case 3:
      spin1.m_rand2 = 'c';
      break;
    case 4:                                                                                                                        
      spin1.m_rand2 = 'd';                                                                                                                        
      break;   
  }
  switch (rand3)
  {
    case 1:
      spin1.m_rand3 = 'a';                                                                                                                        
      break;
    case 2:
      spin1.m_rand3 = 'b';
      break;
    case 3:
      spin1.m_rand3 = 'c';
      break;
    case 4:
      spin1.m_rand3 = 'd';
      break;
  } 
  return spin1;
}

float Option_two(float & bank_balance, const float game_balance)
{
  float new_game_balance, transfer;
  
  //promps user for transpher amount
  cout << "How much money would you like to transfer from your bank account ";
  cout << "into the game?" << endl;
  cin >> transfer;
  
  //if not enough in bank for transfer
  if (transfer > bank_balance)
  {
    cout << "You do not have sufficient funds in the bank." << endl;
  }
  //if not enough in game for reverse transfer (just in case)
  else if (transfer < ( game_balance * (-1)))
    cout << "You do not have sufficient funds in the game." << endl;
  else
  {
    bank_balance = bank_balance - transfer;
    new_game_balance = game_balance + transfer;
  }

  return new_game_balance;
}

float Option_three(float game_balance)
{
  short play_times;
  int winnings, total_winnings = 0;
  Spin spin1;
  
  cout << "How many times would you like to spin?" << endl;
  cin >> play_times;
  
  if ((play_times*5) > game_balance)
    cout << "Insufficient Funds" << endl;   
  else
  {
    for (int i=0; i < play_times; i++)
    {
      if (i < 5)  //5 fair rounds
      {
        spin1 = RandSpin();
      }
      else  //then Mo has the advantage
      {
        spin1 = Cheat(total_winnings);
      }
      cout << spin1.m_rand1 << spin1.m_rand2 << spin1.m_rand3 << "         ";
      winnings = Winnings(spin1);
      total_winnings = total_winnings + winnings;
            
      if (winnings > 0)
        cout << "Win $" << winnings << endl;
      else
        cout << "Lose $" << (winnings * -1) << endl;
      
      game_balance = game_balance + winnings;   
    }
    cout << "Total winnings for this round: $" << total_winnings << endl;
  }
  return game_balance;
}

void Print_spin(const Spin spin1)
{
  cout << spin1.m_rand1 << spin1.m_rand2 << spin1.m_rand3 << endl;
  
  return;
}

int Winnings(const Spin spin1)
{
  short rand1 = spin1.m_rand1, rand2 = spin1.m_rand2, rand3 = spin1.m_rand3;
  int winnings;
  
  if (rand1 == rand2 && rand1 == rand3)
    winnings = MAX_WINNINGS;
  else if (rand1 == rand2 || rand1 == rand3 || rand2 == rand3)
    winnings = MIN_WINNINGS;
  else
    winnings = LOSE;
  
  return winnings;  
}

Spin Cheat(const int total_winnings)
{
  Spin spin1;
  
  if (total_winnings < 0)
  {
    spin1 = RandSpin();
  }
  else  //if they are winning any time after 5 spins, then the "randomly"
       //atomatically lose.
  {
    do
    {
      spin1 = RandSpin();
    }while (spin1.m_rand1 == spin1.m_rand2 || spin1.m_rand1 == spin1.m_rand3 ||
           spin1.m_rand2 == spin1.m_rand3);
  }
  return spin1;
}









