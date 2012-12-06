// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » RandomPlayer.cc Implementation File «             ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	01-12-2012
//
#include <string>
#include <cstdlib> // for exit
#include "Card.h"
#include "CardPile.h"
#include "Trick.h"
#include "Player.h"
#include "RandomPlayer.h"


RandomPlayer::RandomPlayer(string name) : Player("r" + name) {}

RandomPlayer::RandomPlayer(string name, int seed) : Player("r" + name), RandomPlayerSeed(seed), RandomPlayerPRNG(PRNG(seed)) {}

// throwOff:			plays a random card from hand
Card RandomPlayer::throwOff(Trick &trickPile) {
	if (hand.pileSize () == 0) {
		cerr << "Error: empty hand, can't pick any cards! \t(RandomPlayer::throwOff)" << endl;
		exit (1);
	}
	int random = RandomPlayerPRNG (0, hand.pileSize() -1 );
	Card playThisCard = hand.getCardAt (random);
	hand.removeCard (playThisCard);
	//trickPile.addCard (playThisCard, this);
	cout << "    " << getName() << " throws off " << playThisCard << endl;
	return playThisCard;
}

// lead:					tosses any card
Card RandomPlayer::lead(Trick &trickPile) {
  if (hand.pileSize () == 0) {
    cerr << "Error: empty hand, can't pick any cards! \t(RandomPlayer::throwOff)" << endl;
    exit (1);
  }
  int random = RandomPlayerPRNG (0, hand.pileSize() -1 );
  Card playThisCard = hand.getCardAt (random);
  hand.removeCard (playThisCard);
  //trickPile.addCard (playThisCard, this);
  cout << "    " << getName() << " led  " << playThisCard << endl;
  return playThisCard;
}

// followSuit:			gets the trickPile's suit and TRY to play card of that suit
// gets the current suit, iterate through the hand and taking out cards that can be played
// if no cards can be played, pick a random card and play
// otherwise generate a number within bounds of the selected cards and play it
Card RandomPlayer::followSuit(Trick &trickPile) {
	Card::Suit currentTrickSuit = trickPile.getSuit();
	CardPile sameSuitCards;
	for (int i = 0; i < hand.pileSize(); i++) { 		// sort through pile for same suit
		if (hand.getCardAt(i).getSuit() ==  currentTrickSuit) {
			Card cardWithSameSuit = hand.getCardAt(i);
			sameSuitCards.addCard (cardWithSameSuit); 
		}
	}
	// check if the pile of same suit cards is empty
	if (sameSuitCards.pileSize() == 0) { // player has no matching suit
		return throwOff (trickPile);
	}
	int random = RandomPlayerPRNG (0, sameSuitCards.pileSize() - 1);
	Card playThisCard = sameSuitCards.getCardAt (random);
	sameSuitCards.removeCard (playThisCard);
	//	trickPile.addCard (playThisCard, this);
	cout << "    " << getName() << " follows suit with " << playThisCard << endl;
	return playThisCard;
}

/*
int main () {
	Card a ("9C");
	Card b ("3D");
	Card c ("TH");
	RandomPlayer rp ("bob");
	rp.addCard (a);
	rp.addCard (b);
	rp.addCard (c);
	Trick t;
	cout << "rplayer lead: " << rp.lead (t) << endl;
	cout << "the trick pile: ";
	t.print();
	cout << endl;
	cout << "rplayer follow: " << rp.lead (t) << endl;
	cout << "the trick pile: ";
	t.print();
	cout << endl;
}

*/
