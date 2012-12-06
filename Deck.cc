// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » Deck.cc Implementation File «                     ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	27-11-2012
//
#include <string>
#include <iostream>
#include "Card.h"
#include "CardPile.h"
#include "Deck.h"
using namespace std;

Deck::Deck () {}
Deck::~Deck () {}

//	generate:					Creates a full deck of card on heap
void Deck::generate() {
	for (int s = Card::Spades; s <= Card::Hearts; s++) {
		for (int r = Card::Two; r <= Card::Ace; r++) {	
			Card cardToAdd = Card ((Card::Rank) r, (Card::Suit) s);
			addCard (cardToAdd);
		}
	}
}

// playingWithAFullDeck:	Combinatorially check if all the cards exist in the a pile of 52
bool Deck::playingWithAFullDeck () const {
	if (pileSize() != 52) {
		return false;
	}
	for (int r = Card::Two; r <= Card::Ace; r++) {
		for (int s = Card::Spades; s <= Card::Hearts; s++) {
			Card checkThisCard ((Card::Rank) r, (Card::Suit) s);
			if (exists (checkThisCard) == false) {
				return false;
			}
		}
	}
	return true;
}

// operator>>:					Reads in string, calls addCard (string)
extern istream& operator>> (istream& in, Deck& deck) {
	string cardName;
	for(size_t i = 0; i < 52; i++) {
		in >> cardName;
		deck.addCard (cardName);
	}
	return in;
}

//	operator<<					Prints out all cards in a line
extern ostream& operator<< (ostream &out, const Deck &deck) {
	out << deck.showCards();
	return out;
}




//int main () {
//	Deck d;
////	Card x ("9H");
////	d.addCard (x);
////	d.print();
////	cin >> d;
////	d.print();
//	d.generate();
//	d.print();
//	d.setRandomSeed (4);
//	cout << "\n\nShuffled: \n";
//	d.shuffle();
//	d.print();
//	cout << endl;
//	d.setRandomSeed (4);
//	cout << "\nShuffled2: \n";
//	d.shuffle();
//	d.print();
//	cout << endl;
////	Card drawn = d.drawCard ();
////	cout << drawn << endl;
////	cout << "drawn 2nd " << d.drawString () << endl;
////	cout << d << endl;
////	d.print();
////	cout << "heartsval " << d.getHeartsValue() << endl;
////	cout << "full: " << d.playingWithAFullDeck() << endl;
//	cout << "properness: " << d.playingWithAFullDeck() << endl;
//}


