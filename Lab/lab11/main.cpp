//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 11/5/13
//Description: Lab11, main file

#ifndef MAIN_CPP
#define MAIN_CPP

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;


const int MAX_HEALTH = 100; //max health the hero can have 
const int MAX_POISON = 20; //max damage poison can do
const string name = "Cole"; //Player's name
const string d_name = "Love Dragon"; //Dragon's name 

//Des:
//Pre:
//Post:
void fightToTheDeath(Hero h, Dragon d);

int main()
{
  srand(time(NULL));

  int damage = 5; //Damage delt at the start const int heal = -7;
  int heal = -7;//heals the opposite of - amount after initial damaged
  int WanderTimes = 20; //number of times Hero will wonder
  bool isPoisoned = false; //Hero starts off as not poisoned
  bool Dead; //is he dead?

  //Sets hero's name 
  Hero h(name);
  //Sets dragon's name
  Dragon d(d_name);
  
  //Dragon vs Hero!!!
  fightToTheDeath(h, d);
/*  
  //Damages hero
  Dead =  h.takeDamage(damage);
  //Heals hero
  Dead = h.takeDamage(heal);
  //Poisons Hero
  h.setPoisoned(isPoisoned);
  
  //Makes hero wander around x number of times
  for (int i = 0; i < WanderTimes; i++)
  { 
    if (Dead != true)
      Nam.wanderAround();
  }
*/  
  return 0;
}

Hero::Hero(string name)
{
  m_name = name;
  m_health = 100;
  m_isPoisoned = false;
  m_strength = 20;
}

bool Hero::takeDamage(int damage)
{
  bool dead;
  
  m_health -= damage;

  //if player's health is above max, lower it to max
  if (m_health > 100)
    m_health = 100;
  
  //if player is dead, output death message, if not, displays health
  if (m_health <= 0)
  {
    cout << "Alas, " << m_name << "has met their fate!" << endl;
    dead = true;
  }
  else
  {
    cout << m_name << "'s health: " << m_health << endl;
    dead = false;
  }
  
  return dead;
}

void Hero::wanderAround()
{
  int hurt;
  static bool alive;

  hurt = ((rand() % MAX_POISON) + 1);
  
  //harms hero a random poison value
  if (m_isPoisoned == true)
  {
    m_health -= hurt;
  }
  //If health is 0 or below, gives a death statment, if not, then pritns health
  if ((m_health <= 0) && (alive == false))
  {
    cout << "Alas, " << m_name << " has met his fate!" << endl;
    alive = true;
  }
  else if (alive == false)
  {
    cout << m_name << "'s health: " << m_health << endl;
  } 
    
  return;
}

void Hero::setPoisoned(bool isPoisoned)
{
  //sets poison to true
  isPoisoned = true;
  m_isPoisoned = isPoisoned;
  
  return;
}

Dragon:Dragon(string d_name)
{
  m_name = d_name
  m_health = 1000;
  m_firepower = 25;

}

void fightToTheDeath(Hero h, Dragon d)
{

  int hdamage = d.m_firepower; 
  int ddragon = h.m_strength;
  
  do{
  d.m_health -= hdamage;
  h.m_health -= ddragon;
  
  cout << "The dragon delt " << hdamage << " damage." << endl;
  cout << h.m_name << " has " << h.m_health << " left." << endl;
  
  cout << "The human delt " << ddragon << " damage." << endl;
  cout << d.m_name << " has " << d.m_health << " left." << endl;
  }((h.m_health != 0) || (d.m_health != 0)
  
  return;

}

#endif
