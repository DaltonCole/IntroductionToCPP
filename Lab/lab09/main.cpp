//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 10/22/2013
//Description: Lab 09, main. Request user's domain, name, user name and
//      password and outputs rather or not they are allowed to log in.

#include "lab09.h"

int main()
{
  char Domain[SIZE1];
  char full_name[SIZE2];
  char Username[SIZE1];
  char Password[SIZE1];  
  char again;  //do they want to go again
  bool allow;  //do they have access
  
  do
  {  
    //menu prompt
    cout << "======== Log In ========" << endl;
    
    cout << "Enter Domain: ";
    cin.getline(Domain, 10);
    
    cout << "Enter Full Name: ";
    cin.getline(full_name, 20);
    
    cout << "Enter Username: ";
    cin.getline(Username, 10);
    
    cout << "Enter Password: ";
    cin.getline(Password, 10);
    
    //determins if they are allowed to enter
    allow = Allow(Username, Password);
    
    //makes domain all caps
    make_caps(Domain);
    
    //prints if they have access or not
    cout << "-------- Status --------" << endl;
    cout << "Server: " << Domain << endl;
    cout << "User: " << Username << endl;
    
    if (allow == 1)
      cout << "ACCESS GRANTED" << endl << endl;
    else
      cout << "ACCESS DENIED" << endl << endl;
    
    cout << "Try again? (y/n): ";
    cin >> again;
    cin.ignore();
  }while (again != 'n');

  return 0;
}
