//Programmer: Dalton Cole
//Class and Section: CS53, A
//Date: 10/14/2013
//Description: Homework 7. This program will shot darts on a board board
//		and ouput a score and a handicaped score for the patron

#ifndef h7_h
#define h7_h

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

// Global Constants
const short MIN_PLAY = 3; //min beers to play
const short MAX_PLAY = 16; //max beers to play without help
const short SHOTS = 14; //number of shots they get per round
const float RADTODEG = .017453; // PI divided by 180
const float DISTANCETOWALL = 13; //distance from game to wall

const string SOUND1 = "ding ding ding!"; //sound made for first ring
const string SOUND2 = "buuuurrrrppp!"; //sound made for second ring
const string SOUND3 = "Hey Hey!"; //sound made for third ring
const string SOUND4 = "Hmmmmm!"; //sound made for fourth ring
const string SOUND5 = "DOH!"; //sound made for fifth ring

// Structs
struct Point
{
  float m_xcoor;
  float m_ycoor;
};

// Functions

//Des: Greets the user with a friendly message
//Pre: none
//Post: prints a greeting to the screen
void greetings();

//Des: Says goodbye
//Pre: none
//Post: Prints a goodbye message to the screen
void goodbye(); 

//Des: randomly generates a point on the dart board that is hit based on the
//	number of beers the user has had
//Pre: num_beers is MIN_play or greater
//Post: changes dart array to an (x,y) Point of where the dart "landed"
void dart_placement(Point dart[], const int beers);

//Des: the game is played as if the user needs more alchol
//Pre: beers should be greater than 0
//Post: return nothing, but game is played as if user has
//	 consumed too little alchol
void too_low(const int beers);

//Des: the game is played if the user consumed just the right amount of drinks
//Pre: none
//Post: return nothing, but game is played as if the user has
//	consumed more than min number of beers
void just_right(const int beers);

//Des: adds up all the individual scores and returns the total one
//Pre: none 
//Post: returns the total socre for the round
float tot_score(const float score[], const int beers);

//Des: adds up all the individual scores and returns the total handicaped one
//Pre: none
//Post: returns the total handicaped score for the round
float ha_score(const float score[]);

#endif
