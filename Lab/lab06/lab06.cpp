//Name: COLE, DALTON
//Section: C
//Class: CS54
//Date: 10/1/2013
//Description: This program takes user information to create a formula of
//	a cirlce, and then tells the user if their inputed points are
//	within or outside the circle.

#include<iostream>
using namespace std;


struct circle_t
{
  float m_ashift; //the a part of a circle equation
  float m_bshift; // the b part of a circle equation
  float m_radius; // the radius for a circle
};

struct point_t
{
  float m_xcoord; // the x coordinant
  float m_ycoord; // the y coordinant
};

//Des: Prompts the user for the values of a circle and sets the member
//     variables of the input parameter to the values provided by the
//     user
//Pre: none
//Post: sets the variables for a circle
void defineCircle(circle_t &circle);

//Des:  prompts the user for the values of a point and returns a point
//	object whose member variables have been set to those values
//Pre: none
//Post: returns the value of the user's imputed point for a circle
point_t definePoint();

//Des: returns true if the specified point is in the specified circle,
//     false otherwise
//Pre: none
//Post: returns true if the point is inside the circle and false if it
//	is outside the circle
bool isInCircle(const point_t point, const circle_t circle);

int main()
{

  circle_t circle;
  point_t point;
  bool In; //is the coordinate inside or outside the circle
  string placement;
  
  defineCircle(circle);

  //prompts user for (x,y) coordinates 3 times
  for (int i = 0; i<3; i++)
  {
  // user imputs x and y coordinates
  cout << endl << "--Define Point  " << i << "--" << endl;
  point = definePoint();
  In = isInCircle(point, circle);
  
  //seperates the in from the out
  placement = (In)?(" is "):(" is not ");
  
  //print if the coordinate is insdie the circle or not
  cout << "The point (" << point.m_xcoord << "," << point.m_ycoord
       << ")" << placement << "in the circle" << endl;
  }

  return 0;
}

void defineCircle(circle_t &circle)
{

  //user inputs the a,b,and r of a circle and sets that calue to circle
  cout << "--Define Circle--" << endl;
  cout << "Enter Center X Coordinate: ";
  cin >> circle.m_ashift;
  cout << "Enter Center Y Coordinate: ";
  cin >> circle.m_bshift;
  cout << "Enter Radius: ";
  cin >> circle.m_radius;
  
  return;
  
}

point_t definePoint()
{
  point_t point;
  
  cout << "Enter X Coordinate: ";
  cin >> point.m_xcoord;
  
  cout << "Enter Y Coordinate: ";
  cin >> point.m_ycoord;
  
  return point;
  
}

bool isInCircle(const point_t point, const circle_t circle)
{
  float r = circle.m_radius;
  float dx = (point.m_xcoord - circle.m_ashift); 
  float dy = (point.m_ycoord - circle.m_bshift);
  bool In;
  
  if ((r*r) >= (((dx)*(dx))+((dy)*(dy))))
  {
   In = true;
  }
  else
    In = false;
  
  return In;
  
}

//------------------------BONUS------------------------//

//   So far the lab assignments have been great. They follow the CS53
//curriculum perfectly. On average the assignments are perfect length
//they usually take me between an hour and two. The average difficulty
//is perfect as well. Some are harder and some are easier, but on average
//it is perfect. On the grading scale, it's college, so it's okay to be 
//rough on grading, but allowing them be turned in by midnight that night
//without a penalty would be nice. 
