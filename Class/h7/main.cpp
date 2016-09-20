//Name: Dalton Cole
//Class and Section: CS53, A
//date: 10/14/2013
//Description: homework 7, main file

#include "h7.h"

int main()
{
  char go_again;
  int beers;
 
  greetings();
  
  do
  {
    //prompt for num of beers
    cout << "How many beers have you had so far tonight?" << endl;
    cin >> beers;
    
    //seperates them based on num of beers
    if (beers < MIN_PLAY)
      too_low(beers);
    else
      just_right(beers);
  
    cout << "Would you like to play again? (y/n)";
    cin >> go_again;
  }while (go_again != 'n');
  
  goodbye();
  
  return 0;
}
