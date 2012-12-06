// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » Card.cc Implentation File «                       ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	25-11-2012
//
#include <string>
#include <cassert>
#include <iostream>
#include <cstdlib> 		// for exit()
#include "Card.h"
using namespace std;

// STATIC INITIALIZATION OF CARDS
const string Card::RankName = "23456789TJQKA";
const string Card::SuitName = "SDCH";
const int Card::numRanks = RankName.length();
const int Card::numSuits = SuitName.length();
const int Card::numCards = Card::numRanks * Card::numSuits;
const Card Card::TwoOfClubs (Card::Two, Card::Clubs);
const Card Card::QueenOfSpades (Card::Queen, Card::Spades);


// getRank () : a public accessor to rank
Card::Rank Card::getRank () const {
	return (Card::Rank) rank;
}

// getSuit (): a public accessor to suit
Card::Suit Card::getSuit () const {
	return (Card::Suit) suit;
}

// getHeartsValue (): returns value of card, w.r.t. a game of Hearts
int Card::getHeartsValue () const {
	if (getSuit() == 0 && getRank() == 10) {	// 13 if card is Queen of Spades
		return 13;
	}
	if (getSuit() == 3) {							// 1 if suit is of Hearts
		return 1;
	}
	return 0;											// 0 otherwise
}

//	stringIsALegalCard (string): True if first letter is a rank, second letter a suit.
bool Card::stringIsALegalCard (string s) {
	if (s.length() == 2) {
		size_t rankLocation = RankName.find (s.at(0));
		size_t suitLocation = SuitName.find (s.at(1));
		if ((rankLocation != string::npos) && (suitLocation != string::npos)) {
			return true;
		}
	}
	return false;
}

// printString:	returns the string equivlent of the card
string Card::getString () const {
	string name = "";
	name.append ( RankName.substr (getRank(), 1) );
	name.append ( SuitName.substr (getSuit(), 1) );
	return name;
}





// Empty cxr: defaults to Ace of Spades
Card::Card() : rank(Ace), suit(Spades) {}

// Preferred cxr (rank, suit): E.g. Card AceofSpades (Card::Ace, Card::Spades)
Card::Card (Rank r, Suit s) : rank (r), suit (s) {}

// String cxr: check for valid input, then call the preferred cxr
Card::Card (string sCard) {
	if (stringIsALegalCard (sCard)) {
		// Converts substr position in Card::RankName and Card::SuitName
		rank = (Card::Rank) Card::RankName.find(sCard.substr (0,1));
		suit = (Card::Suit) Card::SuitName.find(sCard.substr (1,1));
	} else {
		cerr << "Error: " << sCard << " is not a valid card! \t(Card::Card)" << endl;
		exit (1);
	}
}

Card::~Card() {}






// operator==: true if cards have same rank and suit
extern bool operator== (const Card& c1, const Card& c2) {
	if (c1.getSuit() == c2.getSuit() && c1.getRank() == c2.getRank()) {
		return true;
	}
	return false;
}

// operator<: true if (c1.rank < c2.rank) OR (if same rank, c1.suit < c2.suit)
extern bool operator< (const Card& c1, const Card& c2) {
	if ((c1.getRank() < c2.getRank()) ||
		 (c1.getRank() == c2.getRank() && c1.getSuit() < c2.getSuit())) {
		return true;
	}
	return false;
}

// operator<<: print letter from getRank and getSuit from RankName and SuitName
// Recall:	 Card::RankName = "23456789TJQKA"; Card::SuitName = "SDCH";
extern ostream& operator<< (ostream &out, const Card &c) {
	out << (c.RankName.at(c.getRank())) << (c.SuitName.at(c.getSuit()));
	return out;
}

// operator>> using std input for to a card
extern istream& operator>> (istream& in, Card& c) {
	string input = "";
	cin >> input;
	if (c.stringIsALegalCard (input)) {
		Card::Rank rankLoc = (Card::Rank) c.RankName.find(input.substr (0,1));
		Card::Suit suitLoc = (Card::Suit) c.SuitName.find(input.substr (1,1));
		c = Card (rankLoc, suitLoc);
		return in;
	}
	cerr << "Error: Invalid input " << input << "\t(Card::operator>>)" << endl;
	exit (1);
}

