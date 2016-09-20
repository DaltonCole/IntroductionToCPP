//Programmer: Dalton Cole
//Class and Section: 53, A
//Date: 10/28/13
//Description: Homework 8 Header.This program wil make Mo sound smart by making
//	 five different fables with his own personal touch
//	 (change words in a pre-existing fable.)

#ifndef FABLE_H
#define FABLE_H

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;

    
//Functions

//Des: choses a random word from list 3
//Pre: list 3 must exist in the directory
//Post: returns nothing, but gives list3[] a value from list 3
void list3rand(char list3[]);

//Des: choses a random word from list 4
//Pre: list 4 must exist in the directory
//Post: returns nothing, but gives list4[] a value from list 4
void list4rand(char list4[]);

//Des: changes the words in a fable and prints it
//Pre: the fables must exist in the directory
//Post: returns nothing, but prints the reconstructed fable
void printfable();

//Des: choses a random line from moe-rale file
//Pre: Moe-rale file must exist in the directory
//Post: returns nothing, but gives moe_rale[] a value from moe-rale
void moe_rals(char moe_rale[250]);

//Des: has a 1 in four change of printing moe rant after a period
//Pre: Moe-rants file must exist int he directory
//Post:  returns nothing, but prints a moe-rant possibly
void period();

#endif
