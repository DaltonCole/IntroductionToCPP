//Name: COLE, DALTON
//Class and Section: cs54, C
//Date: 11/12/2013
//Description: Lab12, Compound .cpp file

#include "compound.h"

Compound Compound::operator*(const float amount)
{
  Compound four;
  four.m_name = m_name;
  
  
    
  four.m_kg = m_kg * amount;

  return four;
}
Compound Compound::operator+(const Compound& other)
{
  Compound other2;
  
  other2.m_name = m_name + "-" + other.m_name;
  
  for(int i = 0; i < ELEMENT_COUNT ; i++)
  {
    other2.m_elements[i] = m_elements[i] + other.m_elements[i];
  }
  
  other2.m_kg = m_kg + other.m_kg;
  
  return other2;
}
ostream& operator<<(ostream& stream, const Compound& value)
{
  stream << value.m_name << " (" << value.m_kg << ") ";
  
  for(int i = 0; i < ELEMENT_COUNT; i++)
  {
    if(value.m_elements[i] != 0)
      stream <<  i  << "-" << value.m_elements[i] << ", "; 
  }
  return stream;
}
istream& operator>>(istream& stream, Compound& value)
{
  int element_num, atomic_num;
   
  stream >> value.m_name;
  stream >> element_num;
  
  for(int i =1; i<= element_num; i++)
  {
    stream >> atomic_num;
    stream >> value.m_elements[atomic_num];
  }
  
  stream >> value.m_kg;
  
  return stream;
}
