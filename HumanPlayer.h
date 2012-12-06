#include "Player.h"

#ifndef ___HUMANPLAYER_H__
#define ___HUMANPLAYER_H__
class HumanPlayer : public Player {
 public:
  HumanPlayer(string name);
 private:
  virtual Card followSuit(Trick &currTrick);
  virtual Card throwOff(Trick &currTrick);
  virtual Card lead(Trick &currTrick);
};
#endif
