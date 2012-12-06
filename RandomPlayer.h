// ┌────────────────────────────────────────────────────────────────────────────┐
// │■■                              » RandomPlayer.h Header File «                      ■■│
// └────────────────────────────────────────────────────────────────────────────┘
// Author:	Jason Sun (20387090)
// Date	:	01-12-2012
//
// Interface:
//
// Card followSuit (Trick&)			Tries to choose a random card of that suit. Otherwise use any card
// Card lead (Trick&)					Use any card
//
// Examples:
// 
// Trick t;
// randomPlayer1.lead (t);
// randomPlayer1.followSuit (t);

#ifndef ___RANDOMPLAYER_H__
#define ___RANDOMPLAYER_H__

#include "Player.h"
#include "Trick.h"
#include "PRNG.h"

class RandomPlayer : public Player {
 public:
  RandomPlayer(string name);
  RandomPlayer(string name, int seed);
  Card lead(Trick &currTrick);
  Card followSuit(Trick &currTrick);

 private:
  Card throwOff(Trick &currTrick);
  int RandomPlayerSeed;
  PRNG RandomPlayerPRNG;
};

#endif 

