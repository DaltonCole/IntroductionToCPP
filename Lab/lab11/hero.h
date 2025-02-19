//Name: COLE, DALTON
//Class and Section: CS54, C
//Date: 11/5/13
//Description: Lab11, hero header

#include "main.cpp"

class Hero
{
  private:
    string m_name;
    int m_health;
    bool m_isPoisoned;
    int m_strength;

  public:
    //Des: Sets the name string equal to the private class m_name, health
    //	 is set to maximum, and sets isPoisoned to false 
    //Pre: None
    //Post: will give string name a name, makes the hero at full health,
    //	 and he won't be poisoned.
    Hero(string name);
  
    //Des: Does the specified amount of damage to the hero's health. Negative 
    //	values will heal up to the maximum allowable health for a hero
    //Pre: None
    //Post: If the calling Hero dies (health drops to zero) a message is
    //	 outputted to the screen and true is returned, otherwise, the Hero's
    //	 current health is outputted and false is returned. If the calling
    //	 Hero is already dead, thoing happens and true is returned.
    bool takeDamage(int damage);

    //Des: Does nothing unless the calling Hero is poisoned,
    //	 in which case the Hero is damaged accordingly
    //Pre: None
    //Post: Will damage the Hero if he is poisoned (random value between 0 and
    //	 the max poison damage value) and output the typical death message
    //	 if the user died from poison damage.
    void wanderAround();
    
    //Des: Sets the calling Hero's poisoned state
    //Pre: None
    //Post: If sent true, the Hero will be poisoned, otherwise,
    //	 the Hero will not be poisoned
    void setPoisoned(bool isPoisoned);

};

#endif
