// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » Card.h Header File «                              ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	25-11-2012
//
// Interface:
//
// Rank getRank () 								A public accessor to rank
// Suit getSuit ()								A public accessor to suit
// int getHeartsValue ()						Returns card value, w.r.t. game of Hearts
// bool stringIsALegalCard (string)			True iff first letter a rank, second letter a suit.
// string getString ()							Returns the string equivlent of the card
// operator==										True if cards have same rank and suit
// operator< 										True if (c1.rank < c2.rank) OR (if same rank, c1.suit < c2.suit)
// operator<<										Print letter from getRank and getSuit from RankName and SuitName
// operator>> 										Using std input for to a card
//
// Examples:
//
// Card card1 ()									Constructs Ace of Spades by default
// Card card2 (Card::Two, Card::Hearts)	Constructs Two of Hearts
// Card card3 ("9D")								Constructs Nine of Diamonds
// cin >> card1									Inputs string of form "9H" to make Nine of Hearts
// cout << card3									Prints "9D"
// card2.getRank ()								Returns 7
// card2.getSuit ()								Returns 1

#ifndef __CARD_H__
#define __CARD_H__


#include <string>
using namespace std;

class Card {
	 public:
	enum Rank {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
	static const string RankName;
	static const int numRanks;
	enum Suit {Spades, Diamonds, Clubs, Hearts};
	static const string SuitName;
	static const int numSuits;
	static const int numCards;
	static const Card TwoOfClubs;
	static const Card QueenOfSpades;
	Card ();
	Card (Rank r, Suit s);
	Card (string sCard);
	~Card ();
	Rank getRank () const;
	Suit getSuit () const;
	int getHeartsValue () const;
	static bool stringIsALegalCard (string s);
	string getString () const;

		private:
	Rank rank;
	Suit suit;
};

extern bool operator== (const Card& c1, const Card& c2);
extern bool operator< (const Card& c1, const Card& c2);
extern ostream& operator<< (ostream &out, const Card &c);
extern istream& operator>> (istream& in, Card& c);

#endif



