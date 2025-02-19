//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 11/19/13
//Description: Lab13, DinoPen template header

#ifndef DINOTEMP_H
#define DINOTEMP_H

#include<iostream>
#include<fstream>
using namespace std;

//constants
const int PenSize = 4; //max number of dinos in the pen

template<typename T>
class DinosaurPen;

template<typename T>
ostream& operator<<(ostream& out,const DinosaurPen<T>& pen);


template<class T>
class DinosaurPen
{
  public:
    DinosaurPen(): m_dinoNum(0){} //sets dinoNum to 0
    void add(const T dino); //adds a dino to dinoNum and dino array unless full
    friend ostream& operator << <T>(ostream& out, const DinosaurPen<T>&pen);
     //outputs each dino's call, if possible

  private:
    int m_dinoNum; //number of dinos
    T m_dinoarray[PenSize]; //contains each dino in the pen

};

#include "dino.hpp"

#endif

