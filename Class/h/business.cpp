//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: cpp file for business class

#include "business.h"
//#include "product.h"

business::business()
{
  BusName = "";
  cash = 0;
  itemNum = 0;
  custNum = 0;
}

business::business(const string bus_name, const float cash_money)
{
  string strTOint;
  itemNum =0;
  BusName = bus_name;
  cash = cash_money;
  //opens file containing products and amounts, business depending
  if(bus_name == "Moe's")
  {
    ifstream in("Moe.txt");
    while (in >> items[itemNum].m_price)
    { 
      getline(in, items[itemNum].m_product);
      itemNum++;
    }
  }
  else if(bus_name == "CBG's")
  {
    ifstream in("CBG.txt");
    while (in >> items[itemNum].m_price)
    {
      getline(in, items[itemNum].m_product);
      itemNum++;
    }
  }
  custNum = 0;
}

void business::addCustomer(const customer & person)
{
  cust_obj[custNum] = person;
  custNum++;
  return;
}

void business::sell_stuff()
{
  int awesome; //represents some random awesome product

  for(int i = 0; i < custNum; i++)
  {
    awesome = (rand() % NUM_ITEMS_MOE);

    if (cust_obj[i].buy_something(items[awesome]) == true)
      cash += items[awesome].m_price;
  }
  return;
}

void business::customers_leave(customer custs[], short & num_cust_array)
{
  for(int i = 0; i < custNum; i++)
  {
    custs[i+num_cust_array] = cust_obj[i];
  }
  custNum = 0;

  return;
}

short business::getCustNum()
{
  return custNum;
}
