#include "Player.h"

#ifndef ___SMARTPLAYER_H__
#define ___SMARTPLAYER_H__
class SmartPlayer : public Player {
 public:
  SmartPlayer(string name);
 private:
  virtual Card followSuit(Trick &currTrick);
  virtual Card throwOff(Trick &currTrick);
  virtual Card lead(Trick &currTrick);
};
#endif
