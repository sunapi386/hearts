/*
  File: Player.h     Author: Travis Bartlett     Date Completed: Decemer 1st, 2012

  getName()          -   Returns the name of the player
  printHand()        -   Prints the player hsn
  addCard()          -   Adds a card to the player's hand
  getScore()         -   Retuns the player's current score
  hasCard(Card&)     -   Returns true if the player has the given card
  hasCard(string)        Accepts either a card of it's string representation
  winTrick(Trick&)   -   Gives the player the given trick, updating their
                         pile of tricks they have won and their score
  playCard(Trick&)   -   Returns a card. Calls either followSuit, throwOff
                         or lead, depending on which is appropriate
  followSuit(Trick&) -   Returns a card of the current suit that would be played
  throwOff(Trick&)   -   Returns a card that would be thrown off
                         Assumes the player has no cards of the current suit
  lead(Trick&)       -   Returns a card that would be played to lead the trick
  Above three functions (followSuit, throwOff, and lead) are pure virtual
  and must be implemented in each type of Player


  ---Example usage of Player---
  Player* p = new SmartPlayer("Bob") //Makes a smart player named sBob
  Trick t;
  p->addCard("QS");
  p->addCard("7C");
  p->hasCard("3D"); //False
  p->followSuit(t) //Plays a card, following the suit of t

 */

#ifndef ___PLAYER_H__
#define ___PLAYER_H__

#include <string>
#include "Card.h"
#include "CardPile.h"

#include "Trick.h"



class Player {
 public:
  string getName() const; 
  void printHand() const; 
  void addCard(Card& c); 
  Player(string name); 
  int getScore(); 
  bool hasCard(Card& c) const; 		// const should be used whenever possible like above and here - Jason
  bool hasCard(string s) const; 
  void winTrick(Trick& currTrick); 
  Card playCard(Trick& currTrick); 
  virtual Card followSuit(Trick& currTrick) = 0; 
  virtual Card throwOff(Trick& currTrick) = 0; 
  virtual Card lead(Trick& currTrick) = 0; 
 protected:
  CardPile hand; 
 private:
  CardPile tricks; 
  string name;
};
#endif
