#include "Game.h"

Game::Game()
{
  turnCount = 0;

  playerOne = nullptr;
  playerTwo = nullptr;

  fastPlayer = nullptr;
  slowPlayer = nullptr;
}

Game::Game(Player& one, Player& two)
{
  playerOne = &one;
  playerTwo = &two;

  turnCount = 0;

  std::vector<DM>* teamOne = one.getTeam();
  std::vector<DM>* teamTwo = two.getTeam();

  if (teamOne->size() > 0 && teamTwo->size() > 0)
  {
    if ((*teamOne)[0].getSPED() > (*teamTwo)[0].getSPED())
    {
      fastPlayer = &one;
      slowPlayer = &two;
    }
    else
    {
      fastPlayer = &one;
      slowPlayer = &two;
    }
  }
}

void Game::populatePlayers(Player& one, Player& two)
{
  // *** NEEDS FURTHER LOGIC ***
  playerOne = &one;
  playerTwo = &two;
}

void Game::getPriorityPlayer()
{
  // *** IMPLEMENT PRIORITY/SPEED TIE LOGIC ***
  if (playerOne->getActiveMon().getSPED() > playerTwo->getActiveMon().getSPED())
  {
    fastPlayer = playerOne;
    slowPlayer = playerTwo;
  }
  else
  {
    fastPlayer = playerOne;
    slowPlayer = playerTwo;
  }
}

void Game::takeTurn(BattleChoice oneMove, BattleChoice twoMove)
{
  // call func for swap logic (ie entry hazard etc)

  bool oneSwitch = false;
  bool twoSwitch = false;


  // *** CREATE ROBUST LOGIC TO SWITCH TO DIFFERENT POSITIONS IN BENCH ***
  if (oneMove == 5 | oneMove == 6)
    oneSwitch = true;
  if (twoMove == 5 | twoMove == 6)
    twoSwitch = true;


  if (oneSwitch && playerOne == fastPlayer)
  {
    std::vector<DM>* newTeamOrderOne = fastPlayer->getTeam();

    DM placeHolder = (*newTeamOrderOne)[1];
    (*fastPlayer->getTeam())[1] = (*fastPlayer->getTeam())[0];
    (*fastPlayer->getTeam())[0] = placeHolder;
  }
  else if (twoSwitch)
  {
    std::vector<DM>* newTeamOrderTwo = slowPlayer->getTeam();

    DM placeHolder = (*newTeamOrderTwo)[1];
    (*slowPlayer->getTeam())[1] = (*slowPlayer->getTeam())[0];
    (*slowPlayer->getTeam())[0] = placeHolder;
  }
  else if (oneSwitch)
  {
    std::vector<DM>* newTeamOrderOne = fastPlayer->getTeam();

    DM placeHolder = (*newTeamOrderOne)[1];
    (*fastPlayer->getTeam())[1] = (*fastPlayer->getTeam())[0];
    (*fastPlayer->getTeam())[0] = placeHolder;
  }

  // figure this out later LOL need to implement battle damage and DM hp modification
}
