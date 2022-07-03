#include "Game.h"
#include <iostream>

using namespace std::literals::chrono_literals;

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

  turnCount = 1;

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

  int switchIndexOne = oneMove - 4;
  int switchIndexTwo = twoMove - 4;

  if (oneMove == 5 | oneMove == 6)
    oneSwitch = true;
  if (twoMove == 5 | twoMove == 6)
    twoSwitch = true;

  BattleChoice fastMove, slowMove;

  if (playerOne == fastPlayer)
  {
    fastMove = oneMove;
    slowMove = twoMove;
  }
  else
  {
    fastMove = twoMove;
    slowMove = oneMove;
  }

  DM* fastMon = fastPlayer->getActiveMonPtr();
  DM* slowMon = slowPlayer->getActiveMonPtr();


  if (oneSwitch && playerOne == fastPlayer)
  {
    std::vector<DM>* newTeamOrderOne = fastPlayer->getTeam();

    DM placeHolder = (*newTeamOrderOne)[switchIndexOne];
    (*fastPlayer->getTeam())[switchIndexOne] = *(fastPlayer->getActiveMonPtr());
    *(fastPlayer->getActiveMonPtr()) = placeHolder;
  }
  else if (twoSwitch)
  {
    std::vector<DM>* newTeamOrderTwo = slowPlayer->getTeam();

    DM placeHolder = (*newTeamOrderTwo)[switchIndexOne];
    (*slowPlayer->getTeam())[switchIndexOne] = *(slowPlayer->getActiveMonPtr());
    *(slowPlayer->getActiveMonPtr()) = placeHolder;
  }
  else if (oneSwitch)
  {
    std::vector<DM>* newTeamOrderOne = fastPlayer->getTeam();

    DM placeHolder = (*newTeamOrderOne)[switchIndexOne];
    (*fastPlayer->getTeam())[switchIndexOne] = *(fastPlayer->getActiveMonPtr());
    *(fastPlayer->getActiveMonPtr()) = placeHolder;
  }

  // create a method for calculating damage under normal battle conditions
  if (fastMove == attackOne || fastMove == attackTwo ||
      fastMove == attackThree || fastMove == attackFour)
  {
    calcRegularBattleDamage(*fastMon, fastMon->getMoves()[fastMove - 1], *slowMon);
  }
  if (slowMove == attackOne || slowMove == attackTwo ||
      slowMove == attackThree || slowMove == attackFour)
  {
    calcRegularBattleDamage(*slowMon, slowMon->getMoves()[slowMove - 1], *fastMon);
  }

  turnCount++;
  // figure this out later LOL need to implement battle damage and DM hp modification
}

void Game::calcRegularBattleDamage(DM& attacker, Moves* attack, DM& defender)
{
  srand(time(0));

  

  double physDmg = 42.0 * attack->getBasePower() * attacker.getATK()/static_cast<double>(defender.getDEF());
  physDmg /= 50.0;
  physDmg += 2.0;

  double specDmg = 42 * attack->getBasePower() * attacker.getSPATK()/static_cast<double>(defender.getSPD());
  specDmg /= 50.0;
  specDmg += 2.0;

  double dmg;
  double range;

  if (attack->getMoveProperties()[phys])
    dmg = physDmg;
  else
    dmg = specDmg;

  range = 0.2 * dmg;

  double randomFactor = rand() % static_cast<int>(range);

  dmg = dmg + (randomFactor - 0.5 * range);

  if (checkCrit(attacker, attack))
    dmg *= 1.3333;
  defender.setHP(defender.getHP() - dmg);

  if (defender.getHP() < 0)
    defender.setHP(0);


}

// fix both people critting at the same time due to srand
bool Game::checkCrit(DM& attacker, Moves* attack)
{
  std::this_thread::sleep_for(1500ms);
  int roll = rand() % 100;
  if (roll >= (100 - attack->getCritCh()))
  {
    std::cout << "CRIT!\n";
    return true;
  }
  else
  {
    return false;

  }
}