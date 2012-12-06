// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » CardPile.h Header File «                          ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	26-11-2012
//
// Interface:
//
// void setRandomSeed (uint32_t)		Seeds the prng.
// void shuffle ()						Rearrange card pointers
// bool exists (Card&)					Returns true if card address is found
// bool exists (string)					Returns true if card name is found
// void addCard (Card&)					Given a card reference, add it pile
// void addCard (string)				Given a string, adds it to pile
// void removeCard (Card&)				Given a card, remove it from pile
// void removeCard (string)			Given a string, remove it from pile
// int pileSize ()						Returns the array size
// string showCards ()					Returns string of all cards
// string drawString ()					Returns string of card drawn
// Card drawCard ()						Returns Card that's drawn
// void print ()							Prints card values from deck
// int getHeartsValue ()				Sums the values in the pile
// Card firstCard ()						Returns first card in pile
// Card trumpCard (Card::Suit)		Gets highest rank of trick suit, assumes givenSuit exists!
// getCardAt:								Returns the card at that index location
//
// Examples:
//
// Card x, y, z;							Make 3 default cards
// CardPile newPile;						Make a pile
// Card queen ("QS");					Make a queen of spades
// newPile.addCard ( "4D" );			AddCard with string
// newPile.addCard ( queen );			AddCard with reference
// newPile.removeCard (x);				Removing card from heap
// newPile.print();						Print deck
// cout << newPile.drawString ();	Returns the string
// Card d = newPile.drawCard ();		Returns the drawn card


#ifndef __CARDPILE_H__
#define __CARDPILE_H__


#include <vector>
#include "Card.h"
#include "PRNG.h"
using namespace std;
class CardPile : private vector<Card*> {

	 public:
	CardPile ();
	virtual ~CardPile ();
	void setRandomSeed (uint32_t randomSeed);
	void shuffle();
	bool exists( Card &c ) const;
	bool exists( string cardName ) const;
	void addCard (Card &addThis);
	void addCard (string cardName);
	void removeCard (Card &remThis);
	void removeCard (string cardName);
	int pileSize () const;
	string showCards() const;
	string drawString ();
	Card drawCard ();
	void print () const;
	int getHeartsValue() const;
	Card firstCard () const;
	Card trumpCard (Card::Suit givenSuit) const;
	Card getCardAt (size_t indexLocation) const;

	 private:
	PRNG prng;
	static const uint32_t DefaultRandomSeed;
	int getLocation (Card &c) const;
};

#endif



