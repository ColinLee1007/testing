#ifndef CARD_H
#define CARD_H


class Card
{
    public:
        Card();
        Card(char s);
        Card(char s, char r);

        char getRank();
        char getSuit();

        void setRank(char r);
        void setSuit(char s);


    private:
        char suit;
        char rank;
};

#endif
