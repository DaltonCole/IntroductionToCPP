//Programer: Dalton Cole
//Class and Section: cs53, 1 A
//Date: 10/6/13
//Description: Project header for homework 6. This program uses the user's bank
//	account to transfer funds to a slot machine, then allows the user to
//	play the slots. But Mo will have a slight advantage.
#ifndef h6_h
#define h6_h

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

const short MIN_START = 200;
const short MAX_START = 1000;
const short MIN_SPIN = 1;
const short MAX_SPIN = 4;
const short MAX_WINNINGS = 30;
const short MIN_WINNINGS = 1;
const short LOSE = -5;

struct Spin
{
  char m_rand1;
  char m_rand2;
  char m_rand3;
};

//Des: Greet the user
//Pre: none
//Post: display a greeting message
void Greetings();

//Des: Says goodbye to user and tells user their final balances
//Pre: user presses 4 on menu
//Post: prints the user's final balances and salutations
void Goodbye(const float game_balance, const float bank_balance);

//Des: User selects an item from a displayed menu
//Pre: none
//Post: returns the value user picks on the menu
short Menu();

//Des: Creats three random numbers and makes them letters
//Pre: none
//Post: returns a Spin in letter format
Spin RandSpin();

//Des: Changes three numbers into their corresponding letters and sends them
//	back as a Spin
//Pre: none
//Post: returns a spin with char values
Spin Num_to_Letter(const short rand1, const short rand2, const short rand3);

//Des: Allow user's to transfer funds from their bank to their game balance
//Pre: none
//Post: returns game_balance and alters bank_balance
float Option_two(float & bank_balance, const float game_balance);

//Des: User will gamble using game_balance on the rollete
//Pre: game_balance should be over 5
//Post: returns the new game_balance with winnings/ losings
float Option_three(float game_balance);

//Des: Print the given spin to the screen
//Pre: none
//Post: return nothing but will print the users spin to screen
void Print_spin(const Spin spin1);

//Des: will calculate how much a spin is worth
//Pre: none
//Post: will return the winnings they just won
int Winnings(const Spin spin1);

//Des: this function will help Mo cheat by making it impossible to win 
//	if they are up
//Pre: none, but the user has to have a net gain for it to activate, and
//	have spun at least 5 times
//Post: returns a spin that will be losing if they are up or rand if not
Spin Cheat(const int total_winnings);

#endif
