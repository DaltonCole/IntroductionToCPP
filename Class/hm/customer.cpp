//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: cpp file for customer class

#include "customer.h"
//#include "product.h"

customer::customer()
{
  for (int i = 0; i < SIZE1; i++)
  {
    purchases[i].m_product = "";
    purchases[i].m_price = 0;
  }
  m_name = "";
  purch_num = 0;
  //customer has a random number of money between max_amo and min_amo
  money = ((rand() % (MAX_AMO - MIN_AMO)) + MIN_AMO);
  //Customer has a random number of happiness between max_happiness and min
  happiness = ((rand() % (MAX_HAPPINESS - MIN_HAPPINESS)) + MIN_HAPPINESS);
}
customer::customer(const float mola, const string name)
{
  m_name = name;
  money = mola;
  purch_num = 0;
}
/*
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
*/
bool customer::buy_something(product buy)
{
  int random; // 50-50 shot of buying the item

  random = (rand() %2);

  if(random == 1)
  {
    if(money >= buy.m_price)
    {
      if(purch_num < SIZE1)
      {
        money -= buy.m_price;
        purchases[purch_num] = buy;
        purch_num++;
      }
      else
        random = 0;
    }
    else
      random = 0;
  }
  if (random == 1)
    happiness += 15;
  else
    happiness -= 15;

  return random;
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
/*
void customer::print()
{
  cout << m_name << " has $" << money << " and purchases: ";
  for (int i = 0; i<purch_num; i++)
    cout << purchases[i] << ", ";
  cout << endl;
  return;
}
*/
ostream & operator << (ostream & os, const customer & cust)
{
  os << cust.m_name << " has $" << cust.money << " and purchased: ";

  for(int i = 0; i < cust.purch_num; i++)
  {
    os << cust.purchases[i].m_product << ", ";
  }

  os << endl;

  return os;
}

void customer::throws(customer & cust)
{
  //throws something if the customer has anything to throw
  if (purch_num > 0)
  {
    purch_num--;
    happiness += 5;
    cust.happiness -= 20;
  }
  else
  {
    happiness -= 25;
  }

  return;
}

void customer::rob(customer & cust)
{
  if (purch_num < SIZE1 && cust.purch_num > 0)
  {
    purchases[purch_num + 1] = cust.purchases[cust.purch_num];
    purch_num++;
    cust.purch_num--;
    happiness += 25;
    cust.happiness -= 20;
  }
  else
  {
    happiness -= 5;
  }

  return;
}

short customer::getIff()
{
  return inclination;
}

void customer::setName(string name)
{
  m_name = name;

  return;
}

void customer::setIff(int iff)
{
  inclination = iff;

  return;
}

short customer::gethappiness()
{
  return happiness;
}
