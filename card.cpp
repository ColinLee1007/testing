#include "card.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//testting push
    Card::Card(){
        suit = 'c';
        rank = 'A';
    }
    Card::Card(char s){
        suit = s;
        rank = 'A';
    }
    Card::Card(char s, char r){
        suit = s;
        rank = r;
    }

    char Card::getRank(){
        return rank;
    }
    char Card::getSuit(){
        return suit;
    }

    void Card::setRank(char r){
        rank = r;
    }
    void Card::setSuit(char s){
        suit = s;
    }

    