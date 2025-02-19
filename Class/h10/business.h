//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: header file for business class

#ifndef BUSINESS_H
#define BUSINESS_H

#include "customer.h"
#include "driver.cpp"
//using namespace std;

//constants
const int SIZE2 = 10; //number of items in store
const int SIZE3 = 10; //number of customer objects that can be held
const int NUM_IN_STOCK = 7; //number of items the store currently has

//Des: sets name of the business to the empty string, cash to 0, 
//	size of the arrays to zero
//Pre: none
//Post: sets BusName, cash, and arrays to zero 
//business();

//Des: changes name and money to passed values, customers to zero
//	and reads a file to stock it's shelves
//Pre:
//Post:
//business(const string bus_name, const float cash_money);

//Des: prints business name, list of custoemrs, and list of shelved items
//Pre: none
//Post: returns nothing,but prints to the screen name, # of customers,
//	shelved items
//void printbus()

//Des: adds a customer to the cust_obj array
//Pre: none
//Post: returns nothing, but adds a customer to the cust_obj array
//addCustomer(const customer & person);

//Des: sells an item to a customer for a fixed $40 if they have the funds
//Pre: custoemr must have the funds to purchase said item
//Post: returns nothing, but increases the cash by the fixed amount
//void make_a_sale();

//Des: Call the array of customers to see if they will buy something
//	if the customer does buy something, then funds will be transfered
//	appropriately
//Pre: none
//Post: returns nothing, but changes cash if transaction is succesful
//void sell_stuff();

//Des: represents the customers leaving the business
//Pre: none
//Post: return nothing, but the function will copy all the customers in
//	the business into passed array
//void customers_leave(customer & custs[], int num_of_cust);
class business
{
  private:
    string BusName; //business's name
    float cash; //amount of money in cash register
    product items[20]; //items that the business sells
    customer cust_obj[20]; //customer objects currently in the business
    short itemNum; //holds the size of the data in items
    short custNum; //holds the size of the data in cust_obj 

  public:
    business();
    business(const string bus_name, const float cash_money);
    short getCustNum(); //needs description
    void printbus();
    void addCustomer(const customer & person);
    void make_a_sale();    
    void sell_stuff();
    void customers_leave(customer custs[], short & num_cust_array);
};

#endif
