//Name: COLE, DALTON
//Section and Class: CS54, C
//Date: 10/15/13
//Description: lab08.cpp

#include "lab08.h"

void float_rand(float f_org[])
{
  float num;
  for(int i = 0; i <= (SIZE - 1); i++)
  {
    num = ((rand() % (F_RAND_MAX - F_RAND_MIN + 1)) + F_RAND_MIN);
  
    f_org[i] = (static_cast<float>(num)/F_DIVIDE);
  }
  return;
}

void int_rand(int i_org[])
{
  for(int i = 0; i <= (SIZE - 1); i++)
  {
    i_org[i] = ((rand() % (MAX_RAND - RAND_MIN + 1)) + RAND_MIN);    
  }
  return;
}
