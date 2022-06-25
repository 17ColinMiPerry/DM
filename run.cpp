#include "DM.h"
#include "Player.h"
#include "Game.h"
#include "globals.h"

#include <iostream>

int main()
{
  DM carl(200,200,200,200,200, 4);
  carl.addMove("1", 3, 20);
  carl.addMove("2", 5, 40);
  carl.addMove("3", 7, 60);
  carl.addMove("4", null, 80);

  DM carlos(100, 100, 100, 100, 100, 6);
  carlos.addMove("1", 2, 10);
  carlos.addMove("2", 4, 30);
  carlos.addMove("3", 6, 50);
  carlos.addMove("4", 8, 70);

  std::vector<DM> p1Team;
  p1Team.push_back(carl);
  p1Team.push_back(carlos);

  std::vector<DM> p2Team;
  p2Team.push_back(carl);
  p2Team.push_back(carlos);

  Player p1(p1Team);
  Player p2(p2Team);

  Game gamestate(p1, p2);

  std::cout << (*p1.getTeam())[0].getPrimaryType() << "\n";

  gamestate.takeTurn(benchOne, benchOne);

  std::cout << (*p1.getTeam())[0].getPrimaryType() << "\n";

  gamestate.takeTurn(benchOne, benchOne);

  std::cout << (*p1.getTeam())[0].getPrimaryType() << "\n";




  return 0;
}
