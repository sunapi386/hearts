#include <string>
#include "SmartPlayer.h"

SmartPlayer::SmartPlayer(string name) : Player("s" + name) {}

Card SmartPlayer::lead(Trick &currTrick) {
  Card lowest;
  if (hand.exists("2C")) {
    lowest = Card("2C");
  }
  else {
    Card curr;
    string s = hand.showCards();
    lowest = Card(s.substr(0,2));
    for (unsigned int i = 3; i < (s.length()); i += 3) {
      curr = Card(s.substr(i,2));
      if (curr < lowest) {
	//	cout << curr << " < " << lowest << endl;
	lowest = curr;
      }//if
    }//for
  }//else
  cout << "    "  << getName() << " led " << lowest << endl;
  hand.removeCard(lowest);
  //  cout << lowest << " removed" << endl;
  return lowest;
}//lead

Card SmartPlayer::followSuit(Trick &currTrick) {
  Card toPlay;
  string s = hand.showCards();
  Card trump = Card(currTrick.getTrump(), currTrick.getSuit());
  toPlay = Card(s.substr(0,2));
  for (unsigned int i = 3; i < (s.length()); i += 3) {
    Card curr = Card(s.substr(i,2));
    if (curr.getSuit() == currTrick.getSuit()) {
      if (curr < trump) {
	if ((curr < toPlay) == false) {//curr > toPlay
	  toPlay = curr;
	}//if
      }//if
      else if (curr < toPlay) {
	toPlay = curr;
      }//else if
    }//if
  }//for
  cout << "    " << getName() << " followed suit with " << toPlay << endl;
  hand.removeCard(toPlay);
  return toPlay;
}//followSuit

Card SmartPlayer::throwOff(Trick &currTrick) {
  if (hand.exists("QS")) {
    hand.removeCard("QS");
    return Card("QS");
  }//if
  string cards = hand.showCards();
  Card c;
  if (string::npos != cards.find("H")) { //Do I have a heart to throw off?
    c = hand.trumpCard(Card::Hearts);
  }//if
  else if (string::npos != cards.find("C")) { //If not, try clubs
    c = hand.trumpCard(Card::Clubs);
  }//if
  else if (string::npos != cards.find("D")) { //If not, try diamonds
    c = hand.trumpCard(Card::Diamonds);
  }//if
  else if (string::npos != cards.find("S")) { //if not, try spades
    c = hand.trumpCard(Card::Spades);
  }//if
  hand.removeCard(c);
  cout << "    " << getName() << " throws off " << c << endl;
  return c;
}//throwOff
