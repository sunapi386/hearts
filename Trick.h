// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » Trick.h Header File «                             ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	28-11-2012
// Note: Trick class represents the current trick in play, and keeps track of which
// card was led, which card is currently the trump card, and who played that card.
//
// Interface:
//
// Card::Suit getSuit () 					Get suit of the trick (whatever suit was led)
// Card::Rank getTrump ()					Get highest card of the trick's suit
// Player* getLeader()						Return which player is leading
// void addCard (Card&, Player*)			Given a card reference, add it pile
// void addCard (string, Player*)		Given a string, adds it to pile
//
// Examples:
//
// Trick t;										Makes a new trick pile
// Player *player1 = new Player;			Creates player1, to use for the pointer address
// t.addCard ("2S", player1);				Player1 plays a card "2S"
// t.getSuit();								Returns the led suit
// t.getTrump();								Returns a rank that's of the current led suit
// t.getLeader ();							Returns the pointer to a player who's highest


#ifndef __TRICK_H__
#define __TRICK_H__

#include <iostream>
#include "Card.h"
#include "CardPile.h"

using namespace std;

// Forward declaration of Player.h
class Player;

class Trick : public CardPile {
	 public:
	Trick ();
	virtual ~Trick ();
	Card::Suit getSuit();
	Card::Rank getTrump();
	Player* getLeader(); //Return which player led the trick
	void addCard (Card &playedCard, Player* whoPlayedIt);
	void addCard (string name, Player* whoPlayedIt);

	 private:
	Player *pCurrentLeader;
};

#endif


