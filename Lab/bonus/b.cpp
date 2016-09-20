//Name: COLE, DALTON
//class and section: CS53, c
//date: 10/16/13
//Description: bonus!

#include "b.h"

void numANDchar(Num_Char NC[])
{
  int min1= 0, max1 = 99, min2 = 97, max2 = 122;
  
  for (int i = 0; i < SIZE; i++)
  {
    NC[i].m_num = ((rand() % (max1 - min1 + 1)) + min1); 
  }
  
  for (int i = 0; i < SIZE; i++)
  {
    NC[i].m_char = ((rand() % (max2 - min2 + 1)) + min2);
  }
  
  for (int i = 0; i < SIZE; i++)
  {
    if (i == SIZE-1)
    {
      cout << NC[i].m_num << ", " << NC[i].m_char << endl;
    } 
    else
      cout << NC[i].m_num << ", " << NC[i].m_char << ", ";  
  }
  
  return;
}

void Integer(int Numb[])
{
  int min1 = 0, max1 = 9;
  
  for (int i = 0; i < SIZE; i++)
  {
    Numb[i] = ((rand() % (max1 - min1 + 1)) + min1);
    
    if (i != SIZE - 1)
      cout << Numb[i] << ", ";
    else
      cout << Numb[i] << endl;
  }
  return;
}

void Letters(char letters[])
{
  int min1 = 65, max1 = 90;
  
  for (int i = 0; i <= (SIZE-1); i++)
  {
    letters[i] = ((rand() % (max1 - min1 + 1)) + min1);
  }
  Accending_Let(letters);
  
  for (int i = 0; i <= (SIZE-1); i++)
  {
    if (i != SIZE -1)
      cout << letters[i] << ", ";
    else
      cout << letters[i] << endl;
  }
  return;
}

void Accending_Let(char letters[])
{
  char temp;
  
  for (int j = 0; j <= (SIZE-1); j++)
  {
    for (int i = 0; i <= (SIZE-2); i++)
    {
      if (letters[i] > letters[i+1])
      {
        temp = letters[i+1];
        letters[i+1] = letters[i];
        letters[i] = temp;
      }
    }
  }
  return;   
}
