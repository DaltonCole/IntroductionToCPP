//Name: COLE, DALTON
//Secton and Class: CS54, C
//Date: 10/15/13
//Description: lab08.h

#ifndef LAB08_H
#define LAB08_H

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//Constants
const int SIZE = 21; //number of floats and integers created
const int RAND_MIN = 1;
const int MAX_RAND = 99;
const int F_RAND_MIN = 9;  //floats min and max
const int F_RAND_MAX = 9999;
const float F_DIVIDE = 10000;

//Template

//Des: sorts the array passed to it into ascending order
//Pre: none
//Post: returns a ascending sorted array
template<typename T>
void Sort(T org[])
{
  int temp;
  
  for (int i = 0; i <= SIZE-1; i++)  
  {
    for (int j = 0; j <= SIZE-1; j++)
    {
      if (org[j] > org[j+1])
      {
        temp = org[j+1];
        org[j+1] = org[j];
        org[j] = temp;
      }
    } 
  } 
  return;
} 

//Functions

//Des: randomly assigns SIZE number to the float array 
//Pre: none
//Post: returns nothing, but assigns SIZE number of floats to float array
void float_rand(float f_org[]);

//Des: randomly assigns SIZE number to the int array
//Pre: none
//Post: returns nothing, but assigns SIZE number of ints to int array
void int_rand(int i_org[]);

#endif
