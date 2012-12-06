#include <string>
#include "Player.h"
#include "Trick.h"
#include "Card.h"



void Player::printHand() const {
  hand.print();
  cout << endl;
}

Player::Player(string theName) : name(theName) {}

void Player::addCard(Card& c) {
  hand.addCard(c);
}

string Player::getName() const {
  return name;
}

bool Player::hasCard(string card) const {
  return hand.exists(card);
}

bool Player::hasCard(Card& card) const {
  return hand.exists(card);
}

Card Player::playCard(Trick& currTrick) {
  if (0 == currTrick.pileSize()) {
    //    cout << getName() << " leading" << endl;
    return lead(currTrick);
  }
  string suit = Card::SuitName.substr(currTrick.getSuit(),1);
  //  cout << suit << endl;
  unsigned int found = (hand.showCards()).find(suit);
  if (string::npos != found) {
    //    cout << getName() << " following" << endl;
    return followSuit(currTrick);
  }
  else {
    //    cout << getName() << " throwing off" << endl;
    return throwOff(currTrick);
  }
}

void Player::winTrick(Trick& currTrick) {
  for (int i = 0; i < 4; i++) {
    //    cout << "winTrick loop " << i;
    Card c = currTrick.drawCard();
    //    cout << ", winning " << c << endl;
    tricks.addCard(c);
  }
}

int Player::getScore() {
  return tricks.getHeartsValue();
}
