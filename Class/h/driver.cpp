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
#include<algorithm>
using namespace std;

//constants
const int num_of_cust = 20; //number of customers
const int MAX_HAPPY = 90; //min happy needed for nivana
const int MIN_HAPPY = 10; //min happy needed for sad place
const int ROUNDS = 20; //number of rounds

int main()
{
  //set random to time
  srand(time(NULL));

  string name; //used for name of customer
  int iff; //used for customer's iffiliation
  int times = 1; //counts the number of times the cycle happens
  short num_left = num_of_cust; //number of customers left
  short numCustMoe; //number of customers in Moe's array
  short rand1; //random customer number 1
  int moe_point = 0; //how many points moe has in the end
  int cbg_point = 0; //how many points CBG has in the end
  string strTOint; //string to int for iffiliation
  string winner; //display's the winning business!
  short iwantazero; //number of custumers on the street after they go into
                   //each business
//  customer copy_cat; //copy customer to shuffle array
//  int rand3; //customer switches place with a random customer
  bool leave; //keeps track of rather or not anyone went to shelbyville
  customer copy_cat; //allows copying of a customer for the customer shuffle
  int rand3; //picks a random customer to shuffle

  business Moe("Moe's", 0);
  business CBG("CBG's", 0);

  customer custs[num_of_cust];
  customer shelbyville[num_of_cust];

  //gives each customer their name and iffiliation
  ifstream in("people.txt");
  for(int i = 0; i < num_of_cust; i++)
  {
    getline(in, name, ',');
    custs[i].setName(name);
    getline(in, strTOint);

    if(strTOint == "-1")
      iff = -1;
    if(strTOint == "1")
      iff = 1;
    custs[i].setIff(iff);
  }
  //output the initial array of customers
  for(int i = 0; i < num_of_cust; i++)
    cout << custs[i];
  
  do
  {
    //outputs what round (out of 20) they are on
    cout << endl << "**************Rooooooound " << times << "!!!!*****************" << endl;
    //if a customer is extreamly dpressed or really happy, they leave
    //the double loop is to check the swaped custumers
cout << "\n--------------Who Leaves Today?------------" << endl;

    leave = false; //if no one leaves to shelbyville
    for (int j = 0; j < num_left; j++)
    {
      for (int i = 0; i < num_left; i++)
      {
        short hap = custs[i].gethappiness();
      
        if(hap >= MAX_HAPPY || hap <= MIN_HAPPY)
        {
          name = custs[i].getName();
          if(hap >= MAX_HAPPY)
          {
            cout << name << " has reached nivana at level " << times
               << " and is shipped to Shelbyville House of Loooooove!" << endl;
          }
          if(hap <= MIN_HAPPY)
          {
            cout << name << " falls desperately hopeless at level " << times
               << " and is shipped to Shelbyville House of Deperation." << endl;
          }
          shelbyville[num_of_cust - num_left] = custs[i];
          custs[i] = custs[num_left-1];
          num_left--;
          leave = true;

        }
      }
    }
    if(leave == false)
      cout << "No one left for shelbyville today..." << endl; 
   
    //seperates customers to their perfered business
    for (int i = 0; i < (num_left); i++)
    {
      iff = custs[i].getIff();
      if(iff == 1)
      {
        Moe.addCustomer(custs[i]);
      }
      else if (iff == -1)
      {
        CBG.addCustomer(custs[i]);
      }
    }
    //each customer buys stuff from their respective business
cout<<"\n------------BUYING STUFF--------------"<<endl;
    Moe.sell_stuff();
    CBG.sell_stuff();
    //reads in how many customers are in the first business
    //this is used to put back the customers onto the street
    numCustMoe = (Moe.getCustNum());
    //puts the custumers back in the customer class
    Moe.customers_leave(custs, iwantazero);
    CBG.customers_leave(custs, numCustMoe);
    //the customers interact (i.e. they shuffle)
    random_shuffle(&custs[0], &custs[num_left]);

//    customer copy_cat;
//    int rand3;    
/*    for(int i = 0; i < num_left; i++)
    {
      rand3 = (rand() % num_left);
      copy_cat = custs[i];
      custs[i] = custs[rand3];
      custs[rand3] = copy_cat;
    }
 */   
    
    //customers throw or rob each other
cout<<"\n--------------IN THE STREETS-----------"<<endl;
    for(int i = 0; i < num_left; i++)
    {
      rand1 = (rand() % (num_left));
      if (custs[i].getIff() == custs[rand1].getIff())
        custs[i].rob(custs[rand1]);
      else
        custs[i].throws(custs[rand1]);
    }
    
    //output the whole array of customers
cout << "\n------------How are they now?-----------" << endl;
    for(int i = 0; i < num_left; i++)
      cout << custs[i];
      
    times++;
  }while(times <= ROUNDS && num_left >1); //continues for 20 rounds     
        //or until there is only one person left standing!

  for(int i = 1; i < num_left; i++)
  {
    custs[i].winner(moe_point, cbg_point);
  }
  for(int i = 1; i < (num_of_cust - num_left); i++)
  {
    shelbyville[i].winner(moe_point, cbg_point);
  }

  (moe_point > cbg_point)?(winner = "Moe's"):(winner = "CBG's");
  
  cout << endl << "The winner is " << winner << "!!!!" << endl;
  

  return 0;
}


