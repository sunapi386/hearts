HEARTS
======

A C++ program that simulates the card game of hearts. 
Plain text version of the game including two automated player classes which use different strategies to pick their next card, plus a class modeling a live human player (who is constrained to make only legal plays). 

Any errors you detect should terminate the program with an exit value not equal to 0 and an error message to standard error.

There are 5 parts (see Hearts UML.jpg):
Card.h
CardPile.h
Deck.h
Trick.h
Player.h
RandomPlayer.h
HumanPlayer.h
SmartPlayer.h
Driver.cc

Rules:
No implementation of "going for control" aka "shooting the moon". 
No special Jack of Diamonds. 
No decision whether hearts has been "broken" when deciding what card to play. 
Can play any card at any time, as long as follow suit
Can even drop a heart (or the Queen of Spades) in the first hand
Assume each player always plays the cards dealt to him/her
No implementation of three-card-pass at the beginning of the round. 

Author: Jason Sun & Travis Bartlett
CS 246 Group Project

