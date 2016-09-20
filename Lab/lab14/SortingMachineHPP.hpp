// Name: COLE, DALTON
// Class & Section: CS54, Section c
// Date: Dec. 3 2013
// Description:

#include<iostream>
using namespace std;

template<typename T>
void SortingMachine<T>::sort(T unsorted[])
{
  cout << endl << "Sorting";
  signed long outputMarker = m_size/m_MARKER;
  signed long i = 1;
  while(i < m_size)
  {
    if(i % outputMarker == 0)
      (cout << ".").flush();

    T key = unsorted[i];
    
    signed long j = i-1;
    
    while( j >= 0 && key < unsorted[j])
    {
      unsorted[j+1] = unsorted[j];
      j--;
    }
    unsorted[j+1] = key;
    i++;
  }
  cout << "Done." << endl;
  return;
}

