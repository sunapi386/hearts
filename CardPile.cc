// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » CardPile.cc Implementation File «                 ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	26-11-2012
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib> // for exit
#include "CardPile.h"
#include "Card.h"

const uint32_t CardPile::DefaultRandomSeed = 37;

// Default constructor
CardPile::CardPile() : prng(DefaultRandomSeed) {}
//	Trivial decostructor
CardPile::~CardPile() {
	for (size_t i = 0; i < size(); i++) {
		delete at(i);
	}
	clear();
}
// setRandomSeet:	seeds the prng.
void CardPile::setRandomSeed(uint32_t randomSeed) { prng.seed(randomSeed); }
// cardLocation:	returns position of card in array, returns -1 if unfound
int CardPile::getLocation (Card &c) const {
	for (size_t i = 0; i < size(); i++) {
		if (c == *at(i)) {
			return i;
		}
	}
	return -1;
}
// shuffle:			rearrange card pointers
void CardPile::shuffle() {
	for (int i = size() - 1; i > 0; i--) {
		const int j = prng(i);
		Card* tmp = at(j);
		at(j) = at(i);
		at(i) = tmp;
	}
}
// exists:			returns true if card address is found
bool CardPile::exists ( Card &c ) const {
	if (getLocation (c) != -1) { return true; }
	return false;
}
// exists:			returns true if card card name is found
bool CardPile::exists( string cardName ) const {
	Card c (cardName);
	if (getLocation (c) != -1) { return true; }
	return false;
}
//	addCard:			given a card reference, add the card's address to memory
//						NOTE: assumes the card is proper!
void CardPile::addCard( Card &addThis ) {
// NOTE: CAN ADD ANOTHER DUPLICATE CARD - SO I COMMENTED OUT BELOW
//	if (exists (addThis)) {
//		cerr << "Error: #CardPile::addCard " << addThis << " not added (already exists)!" << endl;
//		return;
//	}
	Card *pNewCard = new Card ( addThis.getString() );
	push_back ( pNewCard );
}
// addCard:			given a valid card name, adds it to pile
void CardPile::addCard (string cardName) {
	if (Card::stringIsALegalCard (cardName)) {
		Card *pCard = new Card (cardName);
		push_back (pCard);
	} else {
		cerr << "Error: " << cardName << " is not a valid name! \t(CardPile::addCard)" << endl;
		exit (1);
	}
}
//	removeCard:		given a card, remove it from vector
void CardPile::removeCard (Card &remThis) {
	int location = getLocation (remThis);
	if (location == -1) {
		cerr << "Error: " << remThis << " doesn't exist! \t(CardPile::removeCard)" << endl;
		exit (1);
	}
	delete (at(location));
	erase ( begin() + location );
}
// removeCard:		removing by string reference
void CardPile::removeCard (string cardName) {
	Card guiltyCard (cardName);
	int location = getLocation (guiltyCard);
	if (location == -1) {
		cerr << "Error: " << guiltyCard << " doesn't exist! \t(CardPile::removeCard)" << endl;
		exit (1);
	}
	delete (at(location));
	erase ( begin() + location );
}
// pileSize:			returns the array size
int CardPile::pileSize () const { return size(); }
//	showCards:			returns string of all cards
string CardPile::showCards() const {
	string allCards = "";
	for (size_t i = 0; i < size (); i++) {
		allCards.append (at(i)->getString());
		allCards.append (" ");
	}
	return allCards;
}
//	print:			prints card values from deck
void CardPile::print() const {
	for (size_t i = 0; i < size (); i++) {
		cout << *at(i) << " ";
//		if ( i%13 == 12 ) { cout << endl; }
	}
//	cout << endl;
}
// getHeartsValue:	sums the values in the pile
int CardPile::getHeartsValue () const {
	int value = 0;
	// third time using a for loop - maybe need abstract helper function or template
	for (size_t i = 0; i < size(); i++) {
		value += at(i)->getHeartsValue();
	}
	return value;
}
// draw:					returns a string and pops off the top card
string CardPile::drawString () {
	if (size() == 0) {
		cerr << "Error: no cards remain to draw from \t(CardPile::drawString)" << endl;
		exit (1);
	}
	string cardName = at (size() - 1)->getString ();
	removeCard (*at (size() - 1));
	return cardName;
}
// drawCard:			returns a Card and pops off the top card
Card CardPile::drawCard () {
	if (size() == 0) {
		cerr << "Error: no cards remain to draw from \t(CardPile::drawCard)" << endl;
		exit (1);
	}
	Card drawnCard = *at (size () - 1);
	removeCard (*at (size () - 1));	
	return drawnCard;
}
// firstCard:				returns the first card
Card CardPile::firstCard () const {
	if (size () == 0) {
		cerr << "Error: no cards remain to draw from \t(CardPile::drawCard)" << endl;
		exit (1);
	}
	return (Card) *at (0);
}
// trumpCard:				Rank of highest card of given suit, assuming givenSuit exists!
Card CardPile::trumpCard (Card::Suit givenSuit) const {
	Card tempTrumpCard = Card (Card::Two, givenSuit);
	for (size_t i = 0; i < size (); i++) {
		if ( at(i)->getSuit() == givenSuit && tempTrumpCard < *at(i)) {
			tempTrumpCard = *at(i);
		}
	}
	return tempTrumpCard;
}

// getCardAt:				Returns the card at that index location
Card CardPile::getCardAt (size_t indexLocation) const {
	if (indexLocation >= size()) {
		cerr << "Error: drawing card out of bounds at index " << indexLocation << "\t(CardPile::getCardAt)" << endl;
		exit (1);
	}
	return *at (indexLocation);
}


