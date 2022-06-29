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

  // helper functions

  void calcRegularBattleDamage(DM& attacker, Moves* attack, DM& defender);

private:
  Player* playerOne;
  Player* playerTwo;

  int turnCount;

  Player* fastPlayer;
  Player* slowPlayer;
};

#endif
