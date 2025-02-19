//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 11/19/13
//Description: Lab13, DinoPen template .hpp file

#include "dinotemp.h"

template<class T>
void DinosaurPen<T>::add(const T dino)
{
  if (m_dinoNum < PenSize)
  {
    m_dinoNum++;
    m_dinoarray[m_dinoNum-1] = dino;
  }
  else
    cout << "Can't fit any more dinosaurs!" << endl << endl;

  return;
}

template<class T>
ostream& operator<<(ostream& out, const DinosaurPen<T>& pen)
{
  if(pen.m_dinoNum > 0)
  {
    for(int i = 0; i < pen.m_dinoNum; i++)
    {
      out << pen.m_dinoarray[i];
    }
    cout << endl;
  }
  else
    out << "No dinosaurs in the Pen!" << endl << endl;
  return out;
}
