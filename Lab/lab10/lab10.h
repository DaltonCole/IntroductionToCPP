//Name: COLE, DALTON
//Class and section: CS54, C
//Date: 10/29/13
//Description: Lab10 header

#ifndef LAB10_H
#define LAB10_H

#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

//Functions

//Des: this function reads in input and outputs the input minus 13 to each 
//	char and outputs the first 500 chars to submit output
//Pre: none
//Post:returns nothing, but prints 'input' onto output "decoded" and
//	prints the first 500 decoded chars to sumbitOutput
void decode(ifstream & input, ofstream & output, ofstream & submitOutput);

#endif
