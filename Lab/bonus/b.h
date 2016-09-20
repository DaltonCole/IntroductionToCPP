//Name: COLE, DALTON
//class and section: CS53, c
//date: 10/16/13
//Description: bonus!

#ifndef h_b
#define h_b

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

//Global constants
const int SIZE = 10;

//Structs

struct Num_Char
{
  int m_num; 
  char m_char;
};

//Functions

//Des: gives Num_Char array num and char values
//Pre: none
//Post: returns nothing, but gives Num_Char array num/ char values, switching
void numANDchar(Num_Char NC[]);

//Des: Gives Numb array integer values
//Pre: none
//Post: gives numb array a list of values
void Integer(int Numb[]);

//Des: gives letters char values
//Pre: none
//Post: gives letters array a list of capital char values
void Letters(char letters[]);

//Des: reorders the letters array into accending ASCII value
//Pre: Letters array should have char between the ASCII value of 65-90
void Accending_Let(char letters[]);

#endif
