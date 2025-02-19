// Name: COLE, DALTON
// Class & Section: CS54, Section C
// Date: Dec. 3 2013
// Description:

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "SortingMachineH.h"

using namespace std;

int main()
{
  const int SMALL  = 1000;
  const int MEDIUM = 10000;
  const int LARGE  = 100000;
  
  srand(time(NULL));
  
  int smallArray[SMALL];
  int mediumArray[MEDIUM];
  int largeArray[LARGE];

  char largeCharArray[LARGE];
  
  for(int i = 0; i < SMALL; i++)
    smallArray[i] = rand();
	
  for(int i = 0; i < MEDIUM; i++)
    mediumArray[i] = rand();
	
  for(int i = 0; i < LARGE; i++)
    largeArray[i] = rand();
	
  for(int i = 0; i < LARGE; i++)
    largeCharArray[i] = ((rand() % (122 - 97)) + 97);	
	
  SortingMachine<int> smallMachine(SMALL);
  SortingMachine<int> mediumMachine(MEDIUM);
  SortingMachine<int> largeMachine(LARGE);
  SortingMachine<char> largeCharMachine(LARGE);
  
  cout << endl << SMALL << " ints";
  clock_t start = clock();
  smallMachine.sort(smallArray);
  float duration = (clock() - start) / static_cast<float>(CLOCKS_PER_SEC);
  cout << "Time: " << duration << " seconds" << endl;

  cout << endl << MEDIUM << " ints";
  start = clock();
  mediumMachine.sort(mediumArray);
  duration = (clock() - start) / static_cast<float>(CLOCKS_PER_SEC);
  cout << "Time: " << duration << " seconds" << endl;

  cout << endl << LARGE << " ints";
  start = clock();
  largeMachine.sort(largeArray);
  duration = (clock() - start) / static_cast<float>(CLOCKS_PER_SEC); 
  cout << "Time: " << duration << " seconds" << endl;
  
  cout << endl << LARGE << " chars";
  start = clock();
  largeCharMachine.sort(largeCharArray);
  duration = (clock() - start) / static_cast<float>(CLOCKS_PER_SEC);
  cout << "Time: " << duration << " seconds" << endl;   

/*
  //just for fun I outputed the large char array. :)
  for(int i = 0; i < LARGE; i++)
    cout << largeCharArray[i] << endl;
*/
 
  
  return 0;
}
