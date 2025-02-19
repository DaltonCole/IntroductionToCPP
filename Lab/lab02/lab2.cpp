//Name: COLE, DALTON
//Class and Section: CS 54, Section C
//Date: 9/3/13
//Description: Lab 2, Party Planning

#include <iostream>
#include<cmath>
using namespace std;

int main()
{
  float people, ppizza, psoda, more_cups, esoda, more_bottles,
        more_pizzas, price, rup_pizzas, dec_price;
   //people, pizza price, soda price, more cups, owned soda, more bottles
   //more pizzas, total price, round up pizzas, decimal price
             
  //Welcome statement and description
  cout << "This program will take the number of people going to a party, "; 
  cout << "the price of pizza, and the price of soda, and output the ";
  cout << "additional number of liters of soda you'll need, number of ";
  cout << "bottles you'll need to buy, the number of pizzas needed to be ";
  cout << "bought, and the total cost of the party to the nearest dollar."
  << endl;

  //Get user to imput the number of people
  cout << "Enter the number of people going to the party: ";
  cin >> people;
  
  //Get user to imput the price of pizza
  cout << "Enter the price per pizza: $";
  cin >> ppizza;

  //Get user to imput the price of soda
  cout << "Enter the price per bottle of soda: $ ";
  cin >> psoda;

  //Output the number of cups of soda from ten 2 liter bottles
  esoda = (10*8.45351)/(people);
  cout << "Starting with 10 bottles of soda, each person will ";
  cout << "get " << esoda << " cups of soda." << endl;

  //Output the number of additional cups of soda needed for each person to
  //get three sodas
  more_cups = (people * 3) - (10*8.45351);
  cout << "You need " << more_cups << " more cups of soda." << endl;

  //Output the number of additional bottles of soda needed
  more_bottles = more_cups / (8.45351);
  more_bottles = static_cast<long>(more_bottles);
  cout << "Which is " << more_bottles << " more bottles." << endl;

  //Output the number of pizzas needed
  more_pizzas = people / 4;
  rup_pizzas = ceil(more_pizzas);
  more_pizzas = static_cast<long>(more_pizzas);
  cout << "You will need " << more_pizzas << " pizzas." << endl;
  cout << "Or, rounding up, you'll need " << rup_pizzas << " pizzas." << endl;

  //output the total price of the party
  price = (more_bottles * psoda) + (more_pizzas * ppizza);
  dec_price = price * static_cast<float>(1.00);
  price= static_cast<short>(price);
  cout << "Total cost of the party: $" << price << endl; 
  cout << " ($" << dec_price << ")" << endl;

  //Terminate the program
  return 0;
}
