//Name: COLE, DALTON
//Class and Section: cs53, 1A
//Date: 9/4/13
//Description: Assignment 02- The user imputs the wavelength of their eye
//	color, their height in meters, and their gender, in order to output
//	a phony phone number

#include <iostream>
using namespace std;

int main()
{
  short gender, def_number, hijk_number, d_num, e_num, f_num;
  float height, eye;
  string fname, lname;

  //Describes the program
  cout << "This program will have you input your eye color wavelength, ";
  cout << "your height in meters, and your gender. It will then output a ";
  cout << "fake phone number!" << endl;
  
  //user enters their name
  cout << "Please enter your first name: ";
  cin >> fname;
  
  cout << "Now please enter your last name: ";
  cin >> lname;
   
  //user imputs their eye color wavelength
  cout << "Please input the wavelength of your eye color in nm units ";
  cout << "(blue = 475, green = 510, orange = 590): ";
  cin >> eye;
  
  //user imputs their height in meters
  cout << "Now, please input your height in meters ";
  cout << " (to the second decimal place for exactness): ";
  cin >> height;
  
  //user imputs their gender as either a 0 for male or 1 for female
  cout << "Finally, please imput your gender ";
  cout << "(0 = male, 1 = female): ";
  cin >> gender;
  
  //computes phone number
  def_number = (eye*height);
  def_number = (def_number%1000);
  d_num = def_number/100;
  e_num = (def_number/10)%10;
  f_num = (def_number%10);
  height = height * height;
  hijk_number = (10 * eye) + (78 * gender) + height;
  
  //out put their fake phone number
  cout << "Name:              " << fname << " " << lname << endl;
  cout << "Phone Number:      " << eye << "-" << d_num << e_num<< f_num << "-";
  cout << hijk_number << endl;
  cout << "My Motto:          'NO!'" << endl;
  cout << "Now leave.";
  
  //terminate
  return 0;
}
