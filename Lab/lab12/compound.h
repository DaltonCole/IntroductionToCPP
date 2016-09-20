//Name: COLE, DALTON
//Class and Section: cs54, C
//Date: 11/12/2013
//Description: Lab12, Compound header

#ifndef COMPOUND_H
#define COMPOUND_H

#include<iostream>
#include<fstream>

using namespace std;

const int ELEMENT_COUNT = 112;

class Compound
{
  private:
    string m_name;
    float m_kg;
    int m_elements[ELEMENT_COUNT];
    
  public:
    //Des: Default Constructor
    //Pre: None
    //Post: Name is initialized to "unknown, mass is initialized, and
    //	all elements are initialized zero
    Compound():m_name("unknown"),m_kg(0),m_elements(){}
    //Des: multiplies the kilograms of compund by the value sent
    //	 and makes no other changes
    //Pre: None
    //Post: changes * so it multiplies kograms and a value
    Compound operator*(const float amount);
    //Des: For two strings, puts the two strings together with a - in between
    //	For two floats, adds them together normally
    //  For two elements, adds their coresponding array value
    //Pre: none
    //Post: returns a string, float, or int depending of what is passed to it
    Compound operator+(const Compound& other);
    //Des: input from the screen the element's name, mass in (), then
    //	the atomic number and number of that elements in the compound
    //Pre: none
    //Post: intput from the screen in the following format: name (m) a1, b2...
    friend ostream& operator<<(ostream& stream, const Compound& value);
    //Des: output to the screen the element's name, mas in (), then
    //	the atomic number and number of that elements in the compound
    //Pre: none
    //Post: output to the screen in the following format: name(m) a1, b2...
    friend istream& operator>>(istream& stream, Compound& value);            
};
#endif
