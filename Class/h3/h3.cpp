//Programer: DALTON COLE
//Class and Section: CS53, 1A
//Date: 9/11/13
//Description: Assignment 02 - the bar

#include <iostream>
using namespace std;

int main()
{
  string person_there, name, drink, teetotaler;
  bool not_drink;
  short age, drinks_buy, drinks_want; //buy is how many drinks the user can buy
  float money, drink_cost, money_left;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  do
  {
    cout << "What is your name my fine customer?" << endl;
    cin >> name;
    
    //seperates barney from everyone else
    if (name == "barney" || name == "Barney")
      cout << "C'mon in Barney!" << endl;
    else 
    {
      //propt to see if they are a teetotaler
      cout << name << " my dear friend, would you ";
      cout << "happen to be a teetotaler?" << endl;
      cin >> teetotaler;
  
      //seperates the teetotaler
      if (teetotaler == "yes" || teetotaler == "Yes")
        cout << "You are not my friend, leave you nasty teetotaler!" << endl;
      else
      {
        do
        {
        //Prompts for age
        cout << "Fantastic " << name << "!";
        cout << " Now, may I ask how old you are?"<<endl;
        cin >> age;
    
        //Seperates ages
        if (age < 18 && age > 2)
          cout << "Sadely, the feds don't allow you to be here, leave!" <<endl;
        else if (age >125 || age <=2)
          cout << "Please enter a valid age (between 2 and 125)" << endl;  
        else
          //loop for incorrect drink
          do
          {
            not_drink = 0; //changes not_drink
            //prompts for perfered drink
            cout << "Great! Now, "<< name <<", what would you like to drink: ";
            cout << "beer, soda, or liquor?" << endl;
            cin >> drink;
       
            if (drink == "soda" || drink == "beer" || drink == "liquor")
            { 
              if (drink == "soda")  //gets rid of soda drinkers
                cout << "We don't soyrv you sissies in dis place!" << endl;
              else
              {
                if (drink == "beer")
                {
                  drink_cost = 2.00;
                }
                else
                  drink_cost = 4.25;
                //promps for how much money the user has
                cout << "Well then " << name << " how much money do";
                cout << " you have then?" << endl;
                cin >> money;
          
                //seperate users based on the amount of money they have
                if (money < drink_cost)
                {
                  //kicks them out if they don't have enough money for even one 
                  cout << "Get outta here, ya bum!" << endl;
                }
                else
                {
                  //tells how much they can buy
                  drinks_buy = (money/drink_cost);
                  cout << name << ", you can buy " << drinks_buy;
                  cout << " glasses of " << drink;
                  cout << " with that amount of dough" << endl;
             
                  //prompts for how many drinks they want
                  cout << "How many drinks would you like to ";
                  cout << "buy with that " << name << "?" << endl;
                  cin >> drinks_want;
            
                  //seperates wanting just the right amount from the rest
                  if (drinks_want != drinks_buy)
                  {  
                    cout << "Come back when you want to spend all"; 
                    cout << " your money!" << endl;
                  }
                  else
                  {
                    //how much money they'll have when they leave
                    //And welcomeing them into the bar
                    money_left = (money - (drink_cost * static_cast<float>(drinks_want)));                  
                    cout << "Come right in, step up to the bar!" << endl;
                    cout << "Oh, and by the way, you will have $";
                    cout << money_left << " in change." <<  endl;
                  }  
              }
            }
            }
            else
            {
              cout << "Please enter a valid drink." << endl;
              not_drink = 1;
            }                
          } while (not_drink == 1);    
        } while (age > 125 || age <= 2);
      }
    }
    cout << "Anybody else there?? (yes or no?)" << endl;
    cin >> person_there;
  } while (person_there == "yes" || person_there == "Yes");
  
  //end program
  return 0;
}
