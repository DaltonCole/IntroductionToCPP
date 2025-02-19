//Name: Dalton Cole
//Class and Section: CS53, A
//date: 10/14/2013
//Description: homework 7, function file

#include "h7.h"

void greetings()
{
  cout << "Welcome custumer to the woderful game of dars!" << endl;
  return;
}

void goodbye()
{
  cout << "Have a wonderful day custumer!" << endl;
  return;
}

void dart_placement (Point dart[], const int beers)
{
  int min1, max1; //min and max the angles can be
  int a1,a2; //these are for the angels
  float d1,d2; //angles to degrees
  
  min1 = (-2*beers);
  max1 = (2*beers);
  
  for (int i = 0; i <= (SHOTS-1); i++)
  {
    a1 = ((rand() % (max1 - min1 + 1)) + min1);
    a2 = ((rand() % (max1 - min1 + 1)) + min1);
    
    d1 = (static_cast<float>(a1) * RADTODEG);
    d2 = (static_cast<float>(a2) * RADTODEG);
    
    dart[i].m_xcoor = (DISTANCETOWALL * (sin(d1) / cos(d1)));
    dart[i].m_ycoor = (DISTANCETOWALL * (sin(d2) / (cos(d2)*cos(d1))));    
  }
  
  return; 
}

void too_low(const int beers)
{
  int score;
  
  score = (.5 * beers);
  cout << "Your score is: " << static_cast<int>(score) << endl;
  
  cout << "DRINK MORE BEER!!!" << endl;
  
  return;
}

void just_right(const int beers)
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);

  Point dart[SHOTS];
  float score[SHOTS];
  string sound[SHOTS];
  float total_score, hand_score;
  
  dart_placement (dart, beers);
  
  //gives each shot a score
  for (int i = 0; i <= (SHOTS-1); i++)
  {
    score[i] = sqrt((dart[i].m_xcoor*dart[i].m_xcoor)
                +(dart[i].m_ycoor*dart[i].m_ycoor));
  }
  
  //gives each score a sound
  for (int i = 0; i <= (SHOTS-1); i++)
  {
    if (score[i] < 1)
      sound[i] = SOUND1;
    if (score[i] > 1 && score[i] < 2)
      sound[i] = SOUND2;
    if (score[i] >2 && score[i] < 3)
      sound[i] = SOUND3;
    if (score[i] >3 && score[i] < 4)
      sound[i] = SOUND4;
    if (score[i] >4)
      sound[i] = SOUND5;    
  }
  
  //just right beers make sound
  if (beers < MAX_PLAY)
  {
    for (int i = 0; i <= (SHOTS-1); i++)
    {
      cout << "x = " << dart[i].m_xcoor << ", y = " << dart[i].m_ycoor
            << "     score = " << score[i] << "       " << sound[i] << endl;
    }
  }
  //too many make no sound
  else
  {
    for (int i = 0; i <= (SHOTS-1); i++)
    {
      cout << "x = " << dart[i].m_xcoor << ", y = " << dart[i].m_ycoor
            << "     score = " << score[i] << endl;
    }
  }
  total_score = tot_score(score, beers);
  hand_score = ha_score(score);
  
  cout << "Your total handicaped score is: " << hand_score << endl;
  cout << "Your total normal score is: " << total_score << endl;

  return;
}

float tot_score(const float score[], const int beers)
{
  float total_score = 0;
  float reg_score;
  
  for(int i = 0; i <= (SHOTS-1); i++)
  {
    total_score = total_score + score[i];
  }
  reg_score = ((total_score / SHOTS) / beers);
  
  return reg_score;
}

float ha_score(const float score[])
{
  float total_score = 0;
  float reg_score, sub_score = 0;
  
  for(int i = 0; i <= (SHOTS-1); i++)
  {
    total_score = total_score + score[i];  
  }
  total_score = (total_score / SHOTS);
  
  for(int i = 0; i <= (SHOTS-1); i++)
  {
    sub_score = (((total_score - score[i])*(total_score - score[i]))
         + sub_score);
  }
  reg_score = (sub_score / SHOTS);
  
  return reg_score;  
}
