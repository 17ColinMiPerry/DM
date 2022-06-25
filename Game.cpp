#include "Game.h"

Game::Game()
{
  turnCount = 0;

  currentPlayer = nullptr;
}

Game::Game(Player one, Player two)
{
  playerOne = one;
  playerTwo = two;

  turnCount = 0;

  std::vector<DM> teamOne = one.getTeam();
  std::vector<DM> teamTwo = two.getTeam();

  if (teamOne.size() > 0 && teamTwo.size() > 0)
  {
    if (teamOne[0].getSPED() > teamTwo[0].getSPED())
      currentPlayer = &playerOne;
    else
      currentPlayer = &playerTwo;
  }
}

void Game::populatePlayers(Player one, Player two)
{
  playerOne = one;
  playerTwo = two;
}

void Game::takeTurn(BattleChoice oneMove, BattleChoice twoMove)
{
  // figure this out later LOL need to implement battle damage and DM hp modification
}
