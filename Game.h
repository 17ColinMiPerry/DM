#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game{

public:
  Game();
  Game(Player& one, Player& two);

  void populatePlayers(Player& one, Player& two);

  void getPriorityPlayer();
  void takeTurn(BattleChoice oneMove, BattleChoice twoMove);

private:
  // *** CONSIDER SWITCHING THESE TO POINTERS ***
  Player* playerOne;
  Player* playerTwo;

  int turnCount;

  Player* fastPlayer;
  Player* slowPlayer;
};

#endif
