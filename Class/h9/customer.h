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
using namespace std;

//constants
const int SIZE1 = 20; //size of purchase array
const int MIN_AMO = 4; //minimum dollar amount a customer can have
const int MAX_AMO = 250; // maximum dolar amount a customer can have

//The customer constructor with no arguments makes the puchase list empty,
//	 clears m_name, and creats a random amount of
//	 money between $4.00 and $250.
//The customer constructor with arguments accepts a
//	 name and some amount of money.
//The purchase function indicates whether or not a purchase was successful
//	and also adds the item passed to it to the purchases array
//	if possible
//The getName function will retrieve the customer's name in the class
//The getMoney function will retrieve the customer's wallet from the class
//The setMoney function will give money a value
//The print function will output the customer's name, money,
//	 and purchased items

class customer
{
  private:
    string purchases[SIZE1]; //describes purchases
    short purch_num; //number of purchases in purchases[] 
    float money; //spending money
    string m_name; //customer's name
  
  public:
    customer();
    customer(const float mola, const string name);
    bool purchase(const string & item);
    string getName();
    float getMoney();
    void setMoney(const int caching);
    void print();

};

#endif
