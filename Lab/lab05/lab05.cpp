// Name: COLE, DALTON 
// Section: C
// Class: CS54
// Date: 9/24/13
// Description: 

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

// ========================================================================= //
// =========================== Function Prototypes ========================= //
// ========================================================================= //

// Purpose: Outputs a prompt to the user for what they want to do
// Pre: None
// Post: Message is printed to the screen
// Return: void
void promptUser();

// TODO: Fill in the prototype and comment header for 
// Purpose: Outputs the range and average of the number of numbers the user
//	picked. 
// Pre: numRands, min, max, and average must be set. If these conditions are
//	not met, the function may not behave as expected
// Post: Message is printed to the screen
// Return: void
void outputAverage(int numRands, int min, int max, float avg);

// Purpose: Generates a random number in a specified range
// Pre: min and max must be set and the condition (min < max) must hold. If
//   these conditions are not met, the function may not behave as expected
// Post: Returns a random number in the specified range
// Params:
//   min - The minimum of the range the random number will be selected from
//   max - The maximum of the range the random number will be selected from
// Return: Returns a random number in the specified range
int randInRange(int min, int max);

// Purpose: Generates the specified number of random numbers in the specified
//   range and returns their average
// Pre: all values parameters must be set before this function is called and
//   the condition (min < max) must hold. If these conditions are not met, the
//   function may not behave as expected
// Params:
//   min - The minimum of the range the random number will be selected from
//   max - The maximum of the range the random number will be selected from
//   numValues - The number of random values that will be generated and 
//     averaged
// Post: Returns the average of the random numbers generated
// Return: Returns the average of the random numbers generated
float averageRand(int min, int max, int numValues);


// ========================================================================= //
// ================================= Main ================================== //
// ========================================================================= //

// TODO: Add sufficient comments throughout the code to clearly explain
//   what is going on

int main()
{
  // declair variables
  char userMenuChoice;
  int rangeMin, rangeMax, numRands;
  float average;
  bool rangeIsSet = false;
  bool doExit = false;
  
  //set the random number equation towards the clock
  srand(time(NULL));

  do
  {
    //calls to the promptUser function
    promptUser();
    cin >> userMenuChoice;
    
    //makes lower case and upper case characters work	
	if(userMenuChoice <= 'Z' && userMenuChoice >= 'A')
      userMenuChoice += 'a' - 'A';

    switch (userMenuChoice)
    {
      case 'a':  //if user chooses a, they have to imput the min and max values
      {
        do
        {
          cout << "Enter the minimum range value: ";
          cin >> rangeMin;
          cout << "Enter the maximum range value: ";
          cin >> rangeMax;
          //min can not be greater than max
          if(rangeMin >= rangeMax)
            cout << "The minimum value must be less than the maximum" << endl;
        }while(rangeMax <= rangeMin);
        rangeIsSet = true;
      }
      break;
      // if the user chooses b, then print their random number
      case 'b':
      {
        if (rangeIsSet == false)
          cout << "Error, you have to set the range first!" << endl;
        else
        {
          // call on the function randInRange
          cout << "Your random number is: " << randInRange(rangeMin, rangeMax) 
               << endl;
        }
      }
      break;
      // if the user chooses c, then the user imputs the number of random nums
      // they want, and then function outputAverage averages them 
      case 'c':
      {
        if (rangeIsSet == false)
          cout << "Error, you have to set the range first!" << endl;
        else
        {
          cout << "How many to average: ";
          cin >> numRands;
          
          average = averageRand(rangeMin, rangeMax, numRands); 

          outputAverage(numRands, rangeMin, rangeMax, average);
        }  
      }
      break;
      // if the user chooses d, the program ends
      case 'd':
      {
        doExit = true;
      }
      break;
      // if the user imputs an invalid option, then the get told that they did
      default:
      {
        cout << "Error, please choose from one of the following options: " 
             << endl;
      }
    }
  }while(!doExit);

  return 0;
}

// ========================================================================= //
// ========================== Function Definitions ========================= //
// ========================================================================= //

//prints the menu
void promptUser()
{
  cout << "============ Options ============\n"
       << "(a) Define Range\n"
       << "(b) Output one random number\n"
       << "(c) Average some random numbers\n"
       << "(d) Exit\n"
       << " > ";
  return;
}

//this function prints the number of random numbers the user imputed
//, the range they asked for, and the average
void outputAverage(int numRands, int min, int max, float avg)
{
  cout << numRands << " random numbers in [" << min << ", " << max 
       << "] resulted in an average of: " << avg << endl;
  return;
}

//this function sets the function randInRange to a random number in the
//specified range
int randInRange(int min, int max)
{
  int randNum = ((rand() % (max - min + 1)) + min);
  return randNum;
  
}

//this function averages the specified number of random numbers
float averageRand(int min, int max, int numValues)
{
  int sum = 0;
  for(int i = 0; i < numValues; i++)
    sum += randInRange(min, max);
  return static_cast<float>(sum) / static_cast<float>(numValues);
}
