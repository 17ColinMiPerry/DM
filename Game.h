#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game{

public:
  Game();
  Game(Player one, Player two);

  void populatePlayers(Player one, Player two);

  void takeTurn(BattleChoice oneMove, BattleChoice twoMove);

private:
  Player playerOne;
  Player playerTwo;

  int turnCount;

  Player* currentPlayer;
};

#endif
