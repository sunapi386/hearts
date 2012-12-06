// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » Trick.cc Implementation File «                    ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	27-11-2012
//
#include <string>
#include <iostream>
#include "Card.h"
#include "CardPile.h"
#include "Trick.h"
using namespace std;


Trick::Trick () {
	pCurrentLeader = NULL;		// No valid leader initially
}

Trick::~Trick() {
}

// getSuit: 							Suit of the trick (Whatever suit was led)
Card::Suit Trick::getSuit () {
	return (Card::Suit) CardPile::firstCard().getSuit();
}

// getTrump: 							Highest card of the trick's suit
Card::Rank Trick::getTrump () {
	Card::Suit leadingSuit = getSuit();
	Card curTrumpCard = trumpCard (leadingSuit);
	return curTrumpCard.getRank();
}

// getLeader							Return which player is leading
Player* Trick::getLeader() {
	return pCurrentLeader;
}


// addCard:								Given a card and player name, adds it to pile
void Trick::addCard (Card &playedCard, Player* whoPlayedIt) {
	if (pCurrentLeader == NULL) {
		pCurrentLeader = whoPlayedIt;
	} else {
		Card highestCard = Card (getTrump(), getSuit());
		if (highestCard < playedCard) {
			pCurrentLeader = whoPlayedIt;
		}
	}
	CardPile::addCard (playedCard);
}

// addCard:								Given a string and player name, adds it to pile
void Trick::addCard (string cN, Player* whoPlayedIt) {
	if (pCurrentLeader == NULL) {
		pCurrentLeader = whoPlayedIt;
	} else {
		Card playedCard = Card (cN);
		Card highestCard = Card (getTrump(), getSuit());
		if (highestCard < playedCard) {
			pCurrentLeader = whoPlayedIt;
		}
	}
	CardPile::addCard (cN);
}




