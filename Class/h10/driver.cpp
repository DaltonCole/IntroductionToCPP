//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: driver file


#include "customer.h"
#include "business.h"
//#include "product.h"
#include<ctime>
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

//constants
const int num_of_cust = 20; //number of customers


struct product
{
  string m_product; //product name
  float m_price; //product price
};

int main()
{
  //set random to time
  srand(time(NULL));
/*
  string name; //used for name of customer
  int iff; //used for customer's iffiliation
struct product
{
  string m_product; //product name
    float m_price; //product price
    };
      int times; //counts the number of times the cycle happens
  short num_left = num_of_cust; //number of customers left
  short numCustMoe; //number of customers in Moe's array
  short numCustCBG; //number of customers in CBG's array
  short interaction; //number of interactions in a cycle
  short rand1; //random customer number 1
  short rand2; //random customer number 2


  business Moe("Moe's", 0);
  business CBG("CBG's", 0);
  
  customer custs[num_of_cust];
  customer shelbyville[num_of_cust];
  customer copy_cust;

  //gives each customer their name and iffiliation
  ifstream in("people.txt"); 
  for(int i = 0; i < num_of_cust; i++)
  {
     getline(in, name, ",");
     custs[i].setName(name);
     getline(in, iff);
     custs[i].setIff(iff);
  }

  do
  {  
    //if a customer is extreamly dpressed or really happy, they leave
    for (int i = 0; i < num_left; i++)
    {
      if(custs[i].gethappiness >= 90 || custs[i].gethappiness <=10)
      {
        shelbyville[num_left-20] = custs[i];
        custs[i] = custs[num_left-1]; //KDJFDFSDFSDJFIEUREFRSDF doesn't re look at the switched one        
        num_left--;        
      }      
    }
    //seperates customers to their perfered business
    for (int i = 0; i < num_left; i++)
    {
      iff = custs[i].getIff();
      
      if(iff == 1)
        Moe.addCustomer(custs[i]);
      else if (iff == -1)
        CBG.addCustomer(custs[i]);
    }
    //each customer buys stuff from their respective business
    Moe.sell_stuff();
    CBG.sell_stuff();
    //reads in how many customers are in each business
    numCustMoe = Moe.getCustNum();
    numCustCBG = CBG.getCustNum();
    //puts the custumers back in the customer class
    Moe.customers_leave(custs, 0);
    CBG.customers_leave(custs, numCustMoe);
    //the customers interact
    interaction = (rand() % num_of_cust);
    for(int i = 0; i < interaction; i++)
    {
      rand1 = (rand() % (numCustMoe + numCustCBG));
      rand2 = (rand() & (numCustMoe + numCustCBG));
      
      copy_cust = custs[rand2];
      custs[rand2] = custs[rand1];
      custs[rand1] = copy_cust;
    }
    //customers throw or rob each other
    for(int i = 0; i < interaction; i++)
    {
      rand1 = (rand() % (numCustMoe + numCustCBG));
      
      if (custs[i].getIff() == custs[rand1].getIff())
        custs[i].rob(custs[rand1]);
      else
        custs[i].throws(custs[rand1]);
    }
  }while(times != 20 && num_left >0);
  
*/
  return 0;
}
