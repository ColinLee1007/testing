// driver.cpp -- driver program to demonstrate the behavior of
// 	  	 the Card class

#include <iostream>
#include <iomanip>
#include "card.h"

using namespace std;

int main() 
{
  Card deck[52];
  Card holder[52];
  char suits[4] = {'c','d','h','s'};
  char ranks[13] = {'A','K','Q','J','T','9','8','7','6','5','4','3','2'};
  int spos = 0;
  int rpos = 0;
  int poscount = 0;

  //Initializing the deck of cards
  while (spos < 52){
    for (int j = 0; j < 4; j++){
      deck[spos].setSuit(suits[j]);
      spos++;
    }
  }
  while (rpos < 52){
    for (int y = 0; y < 13; y++){
      deck[rpos].setRank(ranks[y]);
      rpos++;
    }
  }

  //Perfect shuffle
  for (int x = 0; x < 52; x++){
    if(x % 2 == 0){
      holder[x].setRank(deck[poscount].getRank());
      holder[x].setSuit(deck[poscount].getSuit());
    }
    else{
      holder[x].setRank(deck[poscount + 26].getRank());
      holder[x].setSuit(deck[poscount + 26].getSuit());
      poscount++;
    }
  }
  //Comparing original deck to shuffled one
  cout << "Original Deck" << "|" << "Shuffled Deck" << endl;
  for(int x = 0; x < 52; x++){  
    cout << "         "<< deck[x].getRank() << " ";
    cout << deck[x].getSuit() << " | ";
    cout << holder[x].getRank() << " ";
    cout << holder[x].getSuit() << endl;
  }

  //Calculates how many perfect shuffles it would take to get original deck
  int shufcount = 0;
  poscount = 0;
  Card holder2 [52];

  for (int t = 0; t < 52; t++){
    holder2[t].setRank(holder[t].getRank());
    holder2[t].setSuit(holder[t].getSuit());
  }

  for (int x = 0; x < 52; x++){
    if (holder2[x].getRank() != deck[x].getRank() || holder2[x].getSuit() != deck[x].getSuit()){
      for (int y = 0; y < 52; y++){
        if(y % 2 == 0){
          holder2[y].setRank(holder[poscount].getRank());
          holder2[y].setSuit(holder[poscount].getSuit());
        }
        else{
          holder2[y].setRank(holder[poscount + 26].getRank());
          holder2[y].setSuit(holder[poscount + 26].getSuit());
          poscount++;
        }
      }
      for (int z = 0; z < 52; z++){
        holder[z].setRank(holder2[z].getRank());
        holder[z].setSuit(holder2[z].getSuit());
      }
      poscount = 0;
      shufcount++;
      x = 0;
    }
  }
  //Displays times shuffled
  cout << endl <<"Times needed to shuffled to get back to the orignal deck was " << shufcount << endl;

  return 0;
}
