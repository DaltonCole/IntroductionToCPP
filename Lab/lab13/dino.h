//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 11/19/13
//Description: Lab13, struct header

//#include "dinotemp.h"
#ifndef DINO_H
#define DINO_H
#include<fstream>
#include<iostream>

using namespace std;

struct Xinjiangovenator
{
  friend ostream& operator <<(ostream& out, const Xinjiangovenator Roar);
};

struct Dilophosaurus
{
  friend ostream& operator <<(ostream& out, const Dilophosaurus Rawr);
};

#endif
