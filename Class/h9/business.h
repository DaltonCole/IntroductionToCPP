//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: header file for business class

#ifndef BUSINESS_H
#define BUSINESS_H

#include "customer.h"
using namespace std;

//constants
const int SIZE2 = 10; //number of items in store
const int SIZE3 = 10; //number of customer objects that can be held
const int NUM_IN_STOCK = 7; //number of items the store currently has

//The business constructor with no arguments sets the business to an empty
//	string, the cash to 0, and size of the arrays to 0
//The business constructor with arguments allows the user to pass the
//	business name, the amount of money in the register, sets the number
//	of sutomers to 0, and reads a file to stock the shelves (item array)
//The printbus function prints to the screen the business name, list of 
//	customers and a list of shelf items
//The cust_add function adds a name to cust_obj
//The make_a_sale function randomly assigns an item to each customer for
//	$40, if they have the money to buy it

class business
{
  private:
    string BusName; //business's name
    float cash; //amount of money in cash register
    string items[SIZE2]; //items that the business sells
    customer cust_obj[SIZE3]; //customer objects currently in the business
    short data_size2; //holds the size of the data in items
    short data_size3; //holds the size of the data in cust_obj 

  public:
    business();
    business(const string bus_name, const float cash_money);
    void printbus();
    void cust_add(const customer & person);
    void make_a_sale();    

};

#endif
