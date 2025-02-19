// Programer: DALTON COLE
// Class and Section: CS53, 1A
// Date: 9/29/13
// Description: Assignment 05 - Fractions

#include<iostream>
using namespace std;

struct fraction
{
  float m_num; //numerator
  float m_den; // denomenator
};

//Des: fuction is to ouput a welcome message
//Pre: none
//Post: returns nothing, but outputs message to screen
void Greetings();
//Des: fuction ouputs a parting message
//Pre: none
//Post: returns nothing, but outputs message to screen
void Goodbye();
//Des: displays the menu
//Pre: none
//Post: returns short that represents a menu choice
short Menu();
//Des: store keyboard input to memory for two fractions from the user
//Pre: none
//Post: returns user's inputed fraction, as long as the denometor is not zero
fraction Enter_Fractions();
//Des: displays the fraction sent to it
//Pre: none
//Post: prints the fraction to the screen
void Display_Fraction(const fraction fraction1);
//Des: computes the sum of the two fractions
//Pre: none
//Post: returns the two fractions added togeather
fraction Add_Fractions(const fraction fraction1, const fraction fraction2);
//Des: computes the quotient of the two fractions
//Pre: none
//Post: returns the quotient of the two fractions
fraction Divide_Fractions(const fraction fraction1, const fraction fraction2);
//Des:  simplifies the fraction
//Pre: none
//Post: returns the fraction into its simplist form
fraction Simplify_Fraction(const fraction fraction1);

int main()
{

  short choice;
  fraction  fraction1, fraction2, added_fraction, divided_fraction;
  fraction  simplified1_fraction, simplified2_fraction;
  char change_fraction;
  bool first1; //choice 1 must be first
  
  Greetings();  //Greet the user
  
  //changes fraction 1 and fraction 2 to zero to prevent
  //  a wierd number at the begining
  fraction1.m_num = 0;
  fraction1.m_den = 0;
  fraction2.m_num = 0;
  fraction2.m_den = 0;
    
  do
  {
    choice = Menu();
  
    //option 1 must be selected before other options (exept for 5)
    if (choice == 1 || choice == 5)
      first1 = true;
    if (first1 != true)
    {
      cout << "You must enter a fraction first" << endl;
    }
    else
    {
      switch (choice)
      {
        case 1:
        {
          //displays fractions
          cout << "Your current fractions are: ";
          Display_Fraction(fraction1);
          cout << " and ";
          Display_Fraction(fraction2);
          cout << "Change fractions? (y/n)";
          cin >> change_fraction;
          
          if (change_fraction == 'y')
          {
            fraction1 = Enter_Fractions();
            fraction2 = Enter_Fractions();
          }
        }
        break;
        case 2:
        {
          //add fractions
          added_fraction = Add_Fractions(fraction1, fraction2);
          added_fraction = Simplify_Fraction(added_fraction); 
          cout << "Your two fractions added togeather are: " <<
                added_fraction.m_num << "/" << added_fraction.m_den << endl;
        }
        break;
        case 3:
        {
          //divide fractions
          divided_fraction = Divide_Fractions(fraction1, fraction2);
          divided_fraction = Simplify_Fraction(divided_fraction);
          cout << "Your two fractions divided by one another are: " <<
              divided_fraction.m_num << "/" << divided_fraction.m_den << endl;
        }
        break;
        case 4:
        {
          //simplify the two fractions
          simplified1_fraction = Simplify_Fraction(fraction1);
          cout << "The simplified version of your first fraction is: " <<
              simplified1_fraction.m_num << "/" <<
              simplified1_fraction.m_den << endl;

          simplified2_fraction = Simplify_Fraction(fraction2);
          cout << "The simplified version of your second fraction is: " <<
              simplified2_fraction.m_num << "/" <<
              simplified2_fraction.m_den << endl;
                                                
        }
        break;
        case 5:
        {
        void Goodbye();
        }
        break;
      }
    }
  }while (choice != 5);

  return 0; //end program
}

//greets user
void Greetings()
{
  cout << "Welcome user! We will be having fun with fractions today!" << endl;
  return;
}

//displays the menu
short Menu()
{
  short choice;
  
  do
  {
    cout << "          Menu" << endl;
    cout << "1. Enter Fractions" << endl;
    cout << "2. Add Fractions" << endl;
    cout << "3. Divide Fractions" << endl;
    cout << "4. Simplify Fractions" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;
  } while ((choice != 1) && (choice != 2) && (choice != 3) 
    && (choice != 4) && (choice !=5));
  
  return choice;

}

//user enters a fraction
fraction Enter_Fractions()
{
  fraction fraction1;
  cout << "Enter the numerator of the fraction: ";
  cin >> fraction1.m_num;
  
  do
  {
    cout << "Enter the denominator: ";
    cin >> fraction1.m_den;
  
    if (fraction1.m_den == 0)
      cout << "Please input a non zero denominator." << endl;
  }while (fraction1.m_den == 0);
  
  return fraction1;

}

//Display fractions
void Display_Fraction(const fraction fraction1)
{
  cout << fraction1.m_num << "/" << fraction1.m_den << endl;
  return;
}

//Add fractions
fraction Add_Fractions(const fraction fraction1, const fraction fraction2)
{
  float new_num1, new_num2;
  fraction added_fractions;
  
  new_num1 = fraction1.m_num * fraction2.m_den;
  new_num2 = fraction2.m_num * fraction1.m_den;
  
  added_fractions.m_den = fraction1.m_den * fraction2.m_den;
  added_fractions.m_num = new_num1 + new_num2;
  
  return added_fractions;
  
}

fraction Simplify_Fraction(const fraction fraction1)
{
  int Big, Small, answer = 1.0;
  fraction simplified_fraction;
  // sets the bigger part of the fraction to big and smaller part to Small
  if (fraction1.m_num > fraction1.m_den)
  {  
  Big = fraction1.m_num;
  Small =fraction1.m_den;
  }
  else
  {
  Small = fraction1.m_num;
  Big = fraction1.m_den;
  } 
     
  do
  {  
    answer = Big % Small;
    
    if (answer != 0)
    {
      Big = Small;
      Small = answer;
    }
  }while (answer != 0);       
           
  simplified_fraction.m_num = fraction1.m_num / Small;
  simplified_fraction.m_den = fraction1.m_den / Small;
         
  return simplified_fraction;       
}

fraction Divide_Fractions(const fraction fraction1, const fraction fraction2)  
{
  
  fraction divided_fraction;
  
  divided_fraction.m_num = fraction1.m_num * fraction2.m_den;
  divided_fraction.m_den = fraction1.m_den * fraction2.m_num;
  
  return divided_fraction;
}


void Goodbyes()
{
  cout << "Have a nice day!" << endl;
  return;
}
