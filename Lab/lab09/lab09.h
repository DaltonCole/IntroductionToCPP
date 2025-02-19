//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 10/22/2013
//Description: Lab 09, header. Request user's domain, name, user name
//       and password and outputs rather or not they are allowed to log in.

#ifndef LAB09_H
#define LAB09_H

#include<iostream>
#include<cstring>
using namespace std;

//Global Constants
const int SIZE1 = 10; // max size of domain, username, password
const int SIZE2 = 20; // max size of full name
const char PASSWORD[20] = "9a$$w0R6"; // Passwords

//Functions

//Des: takes username, and password and computes rather
//	or not have the right to access
//Pre: must have null char marking end of data
//Post:  returns True or False on rather or not they have access
bool Allow(const char Username[], const char Password[]);

//Des: Takes the username and sees if they are allowed access
//Pre: must have null char marking end of data
//Post: returns true or false on rather the user can have access or not
bool Allow_user(const char Username[]);

//Des: takes the domain and makes it as all caps
//Pre: must have null char marking end of data
//Post: returns nothing, but makes Domain all caps
void make_caps(char Domain[]);

#endif
