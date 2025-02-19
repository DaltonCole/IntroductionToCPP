//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: cpp file for business class

#include "business.h"
#include "product.h"

business::business()
{
  BusName = "";
  cash = 0;
  itemNum = 0;
  custNum = 0;
}
business::business(const string bus_name, const float cash_money)
{
  itemNum =0;
  BusName = bus_name;
  cash = cash_money;
  //opens file containing products and amounts, business depending
  if(bus_name == "Moe's")
  {
    ifstream in("Moe");
    while(in.good())
    {
      getline(in, m_product.items[itemNum]);
      getline(in, m_price.items[itemNum]);
      itemNum++;
    }
  }
  else if(bus_name == "CBG's")
  {
    ifstream in("CBG.txt");
    while(in.good())
    {
      getline(in, m_product.items[itemNum]);
      getline(in, m_product.items[itemNum]);
      itemNum++;
    }
  }
  custNum = 0;
}
/*
void business::printbus()
{
  cout << "Business name: " << BusName << endl;
  cout << "Customers: ";
  for (int i = 0; i < custNum; i++)
    cout << cust_obj[i].getName() << ", ";
  cout << endl << "Shelf items: ";
  for (int i = 0; i < itemNum; i++)
    cout << items[i] << ", ";
    
  return;
}
*/
void business::addCustomer(const customer & person)
{
  cust_obj[custNum] = person;
  custNum++;
  return;
}
/*
void business::make_a_sale()
{
  int ran = (rand() % NUM_IN_STOCK);
  bool  worked;

  int enough = cust_obj[custNum].getMoney();

  //if you have the minimum amount of money needed to purchase something
  //you may purchase something
  if (enough > COST)
    worked = cust_obj[custNum].purchase(items[ran]);
  else
    worked = false;
    
  if (worked == true)
    enough-=COST;

  return;
}
*/
void business::sell_stuff()
{
  int awesome; //represents some random awesome product
    
  for(int i = 0; i < custNum; i++)
  {
    awesome = (rand() % itemNum);

    if (cust_obj[i].buy_something(items[awesome]))
      cash += items[awesome].m_price; 
  }
  return;
}

void business::customers_leave(customer custs[], short & num_cust_array)
{
  if(num_cust_array == 0)
  {
    for(int i = 0; i < custNum; i++)
    {
      custs[i] = cust_obj[i];
    }
  }
  else
  {
    for(int i = (num_cust_array +1); i < (num_cust_array + custNum); i++)
    {
      custs[i] = cust_obj[i]
    }
  }  
  custNum = 0;

  return;
}

short business::getCustNum()
{
  return custNum;
}










