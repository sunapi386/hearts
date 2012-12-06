#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string name) : Player("h" + name) {}

Card HumanPlayer::lead(Trick &currTrick) {
  if (hand.exists("2C")) {
    cout << "    " << "Player " << getName() << " has 2C and leads with it" << endl;
    hand.removeCard("2C");
    return Card("2C");
  }
  else {
    while (true) {
      string s;
      cin >> s;
      Card c (s);
      if (hand.exists(c) == false) {
	cout << "You do not have " << c << " in your hand." << endl;
      }//if
      else if (c.getSuit() != currTrick.getSuit()) {
	cout << "You have at least one " <<  Card::SuitName.substr(currTrick.getSuit(),1) << ". You must follow suit." << endl;
      }//if
      else {
	hand.removeCard(c);
	cout << "    " << getName() << " follows suit with " << c << endl;
	return c;
      }//else
    }//while
  }
}//lead

Card HumanPlayer::followSuit(Trick &currTrick) {
  string s;
  cout << "Human player " << getName() << " has the following cards:" << endl;
  cout << "    " << hand.showCards() << endl;
  cout << "Which card would you like to play, " << getName() << "? ";
  while (true) {
    cin >> s;
    Card c (s);
    if (hand.exists(c) == false) {
      cout << "You do not have " << c << " in your hand." << endl;
    }//if
    else if (c.getSuit() != currTrick.getSuit()) {
      cout << "You have at least one " <<  Card::SuitName.substr(currTrick.getSuit(),1) << ". You must follow suit." << endl;
    }//if
    else {
      hand.removeCard(c);
      cout << "    " << getName() << " follows suit with " << c << endl;
      return c;
    }//else
  }//while
}//followSuit

Card HumanPlayer::throwOff(Trick &currTrick) {
  string s;
  cout <<  "Which card would you like to play, " << getName() << "? ";
  while (true) {
    cin >> s;
    Card c (s);
    if (hand.exists(c) == false) {
      cout << "You do not have " << c << " in your hand." << endl;
    }//if
    else {
      hand.removeCard(c);
      cout << "    " << getName() << " throws off " << c << endl;
      return c;
    }//else
  }//while
}//throwOff
