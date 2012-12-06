// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » Deck.h Header File «                              ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	27-11-2012
//
// Interface:
//
// void generate ()							Constructs a deck of 52 cards
// bool playingWithAFullDeck ()			Combinatorially check cards to exist in the a pile of 52
// operator>>									Reads in string, calls addCard (string)
// operator<<									Prints out all cards in a line
//
// Examples:
//
// Deck myDeck;								Makes a deck
// myDeck.generate();						Fill it with 52 cards
// myDeck.playingWithAFullDeck();		Checks if full deck
// cin >> myDeck;								Adds new set of (52) cards in


#ifndef __DECK_H__
#define __DECK_H__

#include<iostream>
#include "CardPile.h"
using namespace std;

class Deck : public CardPile {
    public:
	Deck ();
	virtual ~Deck();
	void generate();
	bool playingWithAFullDeck () const;

};

extern istream& operator>> (istream& in, Deck& deck);
extern ostream& operator<< (ostream &out, const Deck &d);



#endif


