// Name: COLE, DALTON
// Class and Section: CS 54, section C
// Date: 9/17/13
// Description: Promp user for number of randon numbers. Generate that 
//		many numbers between -100 and 100 and averages them.

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
  const int MAX_NUM = 100;
  const int MIN_NUM = -100;
  const int DISPLAY_TIMES = 20;
  const double MAX_NUM2 = 1000000000000;
  const double MIN_NUM2 = -1000000000000;
  
  int num_times, random_num, num_total = 0;
  
  double random_num2, num_total2 = 0, average2;
  
  //num total is sum of random numbers
  float average;
  
  char again;
  
  //allow random number use based on clock
  srand(time(NULL));
  
  do 
  {
    //prompts user for number of random numbers
    cout << "Enter the number of random values to be averaged: ";
    cin >> num_times; 
  
    //if user enters less than or equal to 20, output the random numbers
    if (num_times <= DISPLAY_TIMES)
      cout << "Your random numbers are: ";

    //calculate total of random numbers
    num_total = 0;
    for(int i = 0; i < num_times; i++)
    {
      random_num = (rand() % (MAX_NUM - MIN_NUM + 1)) + (MIN_NUM);
      random_num2 = static_cast<double>(rand() % (MAX_NUM2 - MIN_NUM2 + 1)) + (MIN_NUM2);
      
      num_total = num_total + random_num;
      num_total2 = num_total2 + random_num2;
      
      if (num_times <= DISPLAY_TIMES)
        cout << random_num << ", ";     
    } 
    
    if (num_times <= DISPLAY_TIMES)
    cout << endl; 
    
    //averages the sum
    average =static_cast<float> (num_total) /static_cast<float>( num_times);
    average2 = num_total2/ static_cast<double> (num_times); 
    
    //prints random average
    cout << num_times << " random numbers on the [" << MIN_NUM << ",";
    cout << MAX_NUM << "] produced an average of: " << average << endl;
    
    cout << num_times << " random numbers on the [" << MIN_NUM2 << ",";
    cout << MAX_NUM2 << "] produced an average of : " << average2 << endl;
        
    //prompts for repeat program
    cout << "Repeat with a new number of random values? (y/n): ";
    cin >>  again;
    
    cout << endl;
    
  } while (again ==  'y');  

  //end program
  return 0;

}
