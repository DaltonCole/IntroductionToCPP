//Programmer: Dalton Cole
//Class and Section: 53, A
//Date: 10/28/13
//Description: Homework 8 Header.This program wil make Mo sound smart by making
//       five different fables with his own personal touch
//       (change words in a pre-existing fable.)

#include "fable.h"

void list3rand(char list3[])
{
  ifstream in3("list3.txt");
  int randnum, i = 0; //i is number of words into the list
   
  randnum = ((rand() % 13) + 1); //change to constant
  
  do
  {
  in3.getline(list3, 19);
  i++;
  
  }while(i != randnum);
  
  in3.close();
  
  return;
}

void list4rand(char list4[])
{
  ifstream in4("list4.txt");
  int randnum, i=0; //i is number of words into the list
  
  randnum = ((rand() % 23) + 1); // change to constant
  
  do
  {
  in4 >> list4;
  i++;
  }while (i != randnum);
  
  in4.close();
  
  return;
}

void moe_rals(char moe_rale[])
{
  ifstream rale("Moe-rals.txt");
  int randnum = 1, i = 1; //i is number of lines into the list
  
  randnum = ((rand() % 8) + 1);
  
  cout << endl << "The Moe-rale of the story is: \t";
  
  do
  {
  rale.getline(moe_rale, 249);
  i++;
  }while (i != randnum);
  
  rale.close();
  
  return;
} 

void printfable()
{
  char list3[20], list4[20], aORthe[20], Print[20], moe_rale[250];
  char word2[20], word5[20], lastword[20]; //word 2 and 5 of the title
  string fablenumber;
  int into = 0; //number of words into the fable  
  ifstream fablenum;
  //opens a random fable
    int num; //fable number
    
      num = ((rand() % 5) + 1);
      //opens a random fable file
      
        switch(num)
          {
             case 1:
                fablenum.open("fable1.txt");
                cout << "Mo's Fable #1: \t "; 
                break;
             case 2:
                fablenum.open("fable2.txt");
                cout << "Mo's Fable #2: \t";
                break;
             case 3:
                fablenum.open("fable3.txt");
                cout << "Mo's Fable #3: \t";
                break;
             case 4:
                fablenum.open("fable4.txt");
                cout << "Mo's Fable #4: \t";
                break;
             case 5:
                fablenum.open("fable5.txt");
                cout << "Mo's Fable #5: \t";
                break;
          }                                                                                             
  do
  {
    into++;
    fablenum.getline(Print, 19, ' ');
    if (into == 2)  //grabs the second word of the title
    {
      strcpy(word2, Print);
      list3rand(list3);
      cout << list3 << " ";
    }
    else if (into == 5) //grabs the fifth word of the title
    {
      strcpy(word5, Print);
      list4rand(list4);
      cout << list4 << " ";
    }
    else if (strcmp(Print, word2) == 0) //if second word occurs, replace it
    {
      cout << list3 << " ";
    }
    else if (strcmp(Print, word5) == 0) //if fifth word occurs, replace it
    {
      cout << list4 << " ";
    }
    //if a or the occure, replace those with random words from list 4
    else if (strcmp(lastword, "a") == 0 || strcmp(lastword, "the") == 0)
    {
      list4rand(aORthe);
      cout << aORthe << " ";
    }
    //if none of the above occur, just print the original word
    else
    {
      cout << Print << " ";
    }
    //If there is a period (ie end of sentence) then go to period() function
    for(int i = 0; i < 20; i++)
    {
      if(Print[i] == '.')
        period();
    }
    //to remember the last printed word so we know if an a or the occured
    strcpy(lastword, Print);
    
  }while(!fablenum.eof()); //add to notes
  fablenum.close();
  //print moe-rals at the end
  moe_rals(moe_rale);
  cout << moe_rale;    

  return;
}

void period()
{
  ifstream rants("Moe-rants.txt");
  int randnum;
  char rant[500];
  
  //1 in four chance of a moe-rant appearing
  randnum = (rand() % 4);
  
  if (randnum == 0)
  {
    rants.getline(rant, 499);
    cout << rant;
  }
  
  rants.close();

  return;
}
