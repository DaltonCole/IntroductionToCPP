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

bool customer::buy_something(product buy)
{
  int random; // 50-50 shot of buying the item

  random = (rand() %2);
  if(random == 1)
  {
    if(money >= buy.m_price) //must have enough money
    {
      if(purch_num < SIZE1) //must hve room
      {
        money -= buy.m_price; //subrtact price of item from cust's money
        purchases[purch_num] = buy; //add item to purchases
        purch_num++; //increases num of purchases by 1
        cout << m_name << " purchased a " << buy.m_product
             << " for $" << buy.m_price << endl;
      }
      else
      {
        random = 0;
        cout << m_name << " doesn\'t have enough room!" << endl;
      }
    }
    else
    {
      random = 0;
      cout << m_name << " doesn\'t have enough money for a "
           << buy.m_product << endl;
                     
    }
  }
  else
    cout << m_name << " doesn\'t feel like buying anything." << endl;
  if (random == 1)
    happiness += PURCH_H;
  else
    happiness -= PURCH_H;

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

ostream & operator << (ostream & os, const customer & cust)
{
  //money --> happiness --> (if any) purchases
  os << cust.m_name << " has $" << cust.money
     << " with Happiness " << cust.happiness;

  if (cust.purch_num > 0)
  {
    os << " and purchased: ";
    
    for(int i = 0; i < cust.purch_num; i++)
    {
      os << cust.purchases[i].m_product;
      
      if((i+1) < cust.purch_num)
        os << ", ";
    }
  }
  os << ".";
  os << endl;

  return os;
}

void customer::throws(customer & cust)
{
  //throws something if the customer has anything to throw
  if (purch_num > 0)
  {
    purch_num--; 
    happiness += THROW_H_UP;
    cust.happiness -= THROW_H_DOWN;
    cout << m_name << " throws a " << purchases[purch_num].m_product;
    cout << " at " << cust.m_name << endl;
  }
  else
  {
    happiness -= THROW_FAIL;
    cout << m_name << " tried to throw air " 
         << "but missed!" << endl;
  }
  
  return;
}

void customer::rob(customer & cust)
{
//steals if the other person has something, and you have room for it
  if (purch_num < SIZE1 && cust.purch_num > 0)
  {
    cust.purch_num--;
    purchases[purch_num] = cust.purchases[cust.purch_num];
    purch_num++;
    happiness += STEAL_H_UP;
    cust.happiness -= STEAL_H_EVEIL;
    cout << m_name << " stole a " << purchases[purch_num-1].m_product
         << " from " << cust.m_name << endl;
  }
  else
  {
    happiness -= STEAL_H_DOWN;
    cout << m_name << " tried to steal from " << cust.m_name
         << " but they got notin'!" << endl;
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

void customer::winner(int & moe_point, int & cbg_point)
{
  if(inclination == 1)
    moe_point += happiness;
  if(inclination == -1)
    cbg_point += happiness;
    
  return;
}
