//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: cpp file for customer class

#include "customer.h"

customer::customer()
{
  for (int i = 0; i < SIZE1; i++)
    purchases[i] = "";  
  m_name = "";
  //customer has a random number of money between max_amo and min_amo
  money = ((rand() % (MAX_AMO - MIN_AMO)) + MIN_AMO);
}
customer::customer(const float mola, const string name)
{
  m_name = name;
  money = mola;  
  purch_num = 0;
}
bool customer::purchase(const string & item)
{
  bool successful = false; //was the purchase successful or not

  if (purch_num > SIZE1)
  {  
    purchases[purch_num] = item; //adds item to purchases array
    successful = true;
    purch_num++;
  }
  return successful;
}
string customer::getName()
{
  return m_name;
}
float customer::getMoney()
{
  return money;
}
void customer::setMoney(const int caching)
{
  money = caching;
  return;
}
void customer::print()
{
  cout << m_name << " has $" << money << " and purchases: ";
  for (int i = 0; i<purch_num; i++)
    cout << purchases[i] << ", ";
  cout << endl;
  return;  
}
