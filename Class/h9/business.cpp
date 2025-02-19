//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: cpp file for business class

#include "business.h"

const int COST = 7;

business::business()
{
  BusName = "";
  cash = 0;
  data_size2 = 0;
  data_size3 = 0;
}
business::business(const string bus_name, const float cash_money)
{
  data_size2 =0;
  ifstream in("list.txt");
  //read in shelf items from list.txt
  while (in >> items[data_size2])
  {
    data_size2++;
  }
  BusName = bus_name;
  cash = cash_money;
  data_size3 = 0;
}
void business::printbus()
{
  cout << "Business name: " << BusName << endl;
  cout << "Customers: ";
  for (int i = 0; i<data_size3; i++)
    cout << cust_obj[i].getName() << ", ";
  cout << endl << "Shelf items: ";
  for (int i = 0; i<data_size2; i++)
    cout << items[i] << ", ";
    
  return;
}
void business::cust_add(const customer & person)
{
  cust_obj[data_size3] = person;
  data_size3++;
  return;
}
void business::make_a_sale()
{
  int ran = (rand() % NUM_IN_STOCK);
  bool  worked;

  int enough = cust_obj[data_size3].getMoney();

  //if you have the minimum amount of money needed to purchase something
  //you may purchase something
  if (enough > COST)
    worked = cust_obj[data_size3].purchase(items[ran]);
  else
    worked = false;
    
  if (worked == true)
    enough-=COST;

  return;
}
