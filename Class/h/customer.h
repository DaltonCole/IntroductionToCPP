//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: header file for customer class

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include "product.h"
#include<sstream>
using namespace std;

//constants
const int SIZE1 = 20; //size of purchase array
const int MIN_AMO = 4; //minimum dollar amount a customer can have
const int MAX_AMO = 250; // maximum dolar amount a customer can have
const int MIN_HAPPINESS = 0; //min happiness a person can have by default
const int MAX_HAPPINESS = 100; // max happiness a person can have by default
const int STEAL_H_UP = 25; //amount of happiess that goes up by stealing
const int STEAL_H_DOWN = 5; //amount of happiness goes down from a failed attempt
const int STEAL_H_EVEIL = 20; //amount of happiness victum goes down
const int THROW_H_UP = 5; //happiness goes up successful throw
const int THROW_H_DOWN = 20; //happiness does down victum
const int THROW_FAIL = 25; //happiness goes down from throw fail attempt
const int PURCH_H = 15; //amount of happiness a purchases increase or decrease

//Des: will establish an empty list of purchases, no name, and rand amount
//      of money between 4 and 250, and happiness from 0-100
//Pre: none
//Post: empties everything but money, gives money a value between 4-250
//      and happiness from 0-100
//customer()

//Des: accepts arguments for name and money, sets purchases to 0
//Pre: none
//Post: gives name and money value, purchases equals 0
//customer(const float mula, const string name)

//Des: returns true if the purchase was successful, also adds the item to
//      list of purchases if true
//pre: none
//post: adds the sent string to the end of purchases array if possible
//      , if this happens, then true is returned
//bool purchase(const string & item)

//Des: 50% change of buying something, if buying something then the customer
//      randomly picks and item from the business and buys it (if they have
//      enough money). If bought, the business increases it's funds by the
//      price of the item, and the customer loses that much money.
//      The item is then added to the customer's purchases array.
//      ALSO, if the purchase is sucessful, the customer's
//      happiness goes up by 15, otherwise it goes down by 10
//Pre: none
//Post: returns a bool on rather or not the purchase was successful
//bool buy_something()

//Des:returns the name of the customer
//Pre: none
//Post: the name of the customer is returned
//string getName()

//Des: returns the value of money
//Pre: none
//Post: the value of money is returned
//float get money()

//Des: changes the money member variable
//Pre: none
//post: returns nothing, but changes the money member variable
//void setMoney(const int caching)

//Des: The customer throws a purchase at someone who attends the other
//business
//      (the item disipears). If the throw is successful, the perp's
// happiness
//      increases by 5 and the victums deceasses by 20
//Pre: the victum must be a customer of the other business
//Post: returns nothing, but changes the happiness of two customers and
//      changes one customer's purchases list
// void throw();

//Des: The customer steals an item from another customer if the customer
//      goes to the same business. The perp's happiness incrases by 25
//      and the victum's decreases by 20
//Pre: the victum must be of the same business
//Post: returns nothing, but changes product lists of two customers and
//      happiness of two customers
//void rob();

//Des: prints to the screen a sentence in this format:
//      <name> has $ <money> and purchases <item1.....>
//pre: none
//post: returns nothing, but prints to the screen the member variables
//      in a readable format
//friend ostream & operator << (ostream & os, const customer & x)

//Des: gets the inclination value of the class
//Pre: none
//Post: returns the inclination value
//short getIff()

//Des: gets the happiness value of the class
//Pre: none
//Post: returns the happiness value
//short gethappiness()

//Des: changes the m_name variable of the class
//Pre: none
//Post: returns nothing, but changes the m_name variable
// void setName(string name);

//Des: changes the inclination of the class
//Pre: none
//Post: returns nothing, but changes the inclination variable
// void setIff(int iff);

class customer
{
  private:
    product purchases[SIZE1]; //describes purchases
    short purch_num; //number of purchases in purchases[]
    float money; //spending money
    string m_name; //customer's name
    short happiness; //happiness of the person from 0-100
    short inclination; //what store they want to go to, value of -1 or 1

  public:
    customer();
    customer(const float mola, const string name);
    bool buy_something(product buy);
    string getName();
    short getIff();
    short gethappiness();
    void setName(string name); 
    void setIff(int iff);
    float getMoney();
    void setMoney(const int caching);
    void throws(customer & cust);
    void rob(customer & cust);
    void winner(int & moe_point, int & cbg_point);
    friend ostream & operator << (ostream & os, const customer & cust);
};


#endif
