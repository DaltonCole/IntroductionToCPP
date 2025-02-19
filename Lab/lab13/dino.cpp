//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 11/19/13
//Description: Lab13, .cpp file for everything but templates

#include "dinotemp.h"
#include "dino.h"

int main()
{
  Xinjiangovenator dino1, dino2, dino3, dino4, dino5;
  Dilophosaurus dino6;
  DinosaurPen<Xinjiangovenator> pen1;
  DinosaurPen<Dilophosaurus> pen2;
  
  cout << pen1;
  
  pen1.add(dino1);
  cout << pen1;

  pen1.add(dino2);
  pen1.add(dino3);
  pen1.add(dino4);
  pen1.add(dino5);  
  cout << pen1;

  pen2.add(dino6);
  cout << pen2;

  return 0;
}


ostream& operator<<(ostream& out, const Xinjiangovenator Roar)
{
  out << "Meow...purrrrrr" << endl;
  return out;
}

ostream& operator <<(ostream& out, const Dilophosaurus Rawr)
{
  out << "Hello!, I'm a talking Dilophosaurus!" << endl;
  return out;
}
