#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Card.h"
#include "CardPile.h"
#include "Deck.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "SmartPlayer.h"
using namespace std;

int main(int argc, char* argv[]) {
  bool givenDeck = false;
  bool givenPlayers = false;
  Deck d;
  int seed = 37;
  int maxScore = 40;
  int i = 1, hand = 1;
  Player *players[4];
  Player* leader = NULL;
  while (i < argc) {
    if (string(argv[i]) == "-r") {
      i++;
      seed = atoi(argv[i]);
    }//else if
    else if (string(argv[i]) == "-s") {
      i++;
      maxScore = atoi(argv[i]);
    }//else if
    else if (string(argv[i]) == "-d") {
      givenDeck = true;
      i++;
      ifstream ifs(argv[i]);
      ifs >> d;
    }//else if
    else if (string(argv[i]) == "-p") {
      givenPlayers =true;
      i++;
      for (int j = 0; j < 4; j++) {
	if (string(argv[i+1]) == "H") {
	  players[j] = new HumanPlayer(argv[i]);
	  i += 2;
	}//if
	else if (string(argv[i+1]) == "S") {
	  players[j] = new SmartPlayer(argv[i]);
	  i += 2;
	} //if
	else if (string(argv[i+1]) == "R") {
	  if (atoi(argv[i+2]) == 0) {
	    cerr << "Expected non-zero seed for random player " << argv[i] << endl;
	    return 2; //Missing ranndom player seed = exit code 2
	  } //if
	  players[j] = new RandomPlayer(argv[i], atoi(argv[i+2]));
	  i += 3;
	}//if
      
	else {
	  cerr << "The player kind must be either \"H\", \"S\", or \"R\", not \"" << argv[i] << "\"" << endl;;
	  return 1; //Illegal player type = exit code 1
	} //else
      }//for
    }//else if
    i++;
  }//while
  if (givenDeck == false) { d.generate();}
  d.setRandomSeed(seed);
  if (givenPlayers == false) {
    players[0] = new SmartPlayer("Alice");
    players[1] = new SmartPlayer("Bob");
    players[2] = new SmartPlayer("Carole");
    players[3] = new SmartPlayer("Ted");
  }//if
  d.shuffle();
  
  int j;
  while (true) {
    cout << "At the beginning of hand " << hand << ", here is the deck:" << endl;
    cout << "    " << d << endl;
    cout << endl << endl;
    for (int i = 0; i < 13; i++) {
      for (int j = 0; j < 4; j++) {
	Card c = d.drawCard();
	players[j]->addCard(c);
      }//for
    }//for
    cout << "Here are the hands for each player at the start of hand number " << hand << endl << endl;
    for (int i = 0; i < 4; i++) {
      cout << players[i]->getName() << " has these cards:" << endl << "    ";
      players[i]->printHand();
      cout << endl;
    }//for

    for (int round = 1; round < 14; round++) {
      cout << endl << "Now starting round " << round << " of hand " << hand << endl;
      Trick currTrick;
      if (leader == NULL) {
	for (int i = 0; i < 4; i++) {
	  if (players[i]->hasCard("2C")) {
	    j = i;
	  }//if
	}//for
      }//if
      else {
	for (int i = 0; i < 4; i++) {
	  if (leader == players[i]) {
	    j = i;
	  }//if
	}//for
      }//else
      for (int i = j; i < j+4; i++) {
	Player* p = players[i%4];
	Card c = p->playCard(currTrick);
	//	cout << c << " Trick is " << currTrick.showCards()  << endl; //For debugging, prints card that was played
	currTrick.addCard(c,p); 
	//	cout << "Trick is " << currTrick.showCards() << endl; //Debugging, prints the trick
      }//for
      leader = currTrick.getLeader();
      cout << leader->getName() << " won the trick and added the following cards:" << endl;
      cout << "    " << currTrick.showCards() << endl << endl;
      leader->winTrick(currTrick);
      //      cout << "Trick is " << currTrick.showCards() << endl;
    }//for
    int score[4], lowest = players[0]->getScore();
    bool someoneLost = false;
    Player* loser = NULL, *lowPlayer = players[0];
    cout << "At the end of hand " << hand << " the score is:" << endl;
    for (int i = 0; i < 4; i++) {
      score[i] = players[i]->getScore();
      cout << "    " << players[i]->getName() << "  " << score[i] << endl;
      if (score[i] > maxScore) {
	someoneLost = true;
	loser = players[i];
      }
      if (score[i] < lowest) {
	lowest = score[i];
	lowPlayer = players[i];
      }
    }
    if (loser != NULL) {
      cout << "The game is over." << endl;
      cout << loser->getName() << " has exceeded " << maxScore << " points." << endl;
      cout << "The winner is " << lowPlayer->getName() << endl;
      break;
    }
    hand++;
    d.generate();
    //    d.setRandomSeed(seed);
    d.shuffle();
  }//while
  for (int i = 0; i < 4; i++) {
    delete players[i];
  }//for
  return 0;
}//main
