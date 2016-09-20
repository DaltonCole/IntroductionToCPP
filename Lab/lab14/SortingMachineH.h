// Name: COLE, DALTON
// Class & Section: CS54, Section c
// Date: Dec. 3 2013
// Description:

#ifndef SORTSH_H
#define SORTSH_H

template<typename T>
struct SortingMachine
{
  private:
    int m_size;
    const static int m_MARKER = 50;
	
  public:
    SortingMachine(const int size): m_size(size) {}
    //Des: This function takes a type and sorts it from least to greatest
    //Pre: the type must have a numerical type associated with it
    //Post: This function returns nothing, but sorts passed values
    //		from least to greatest
    void sort(T array[]);
};

#include "SortingMachineHPP.hpp"
#endif
