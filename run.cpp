#include "DM.h"
#include "Player.h"
#include "Game.h"
#include "globals.h"
#include "helper.h"

#include <iostream>

using namespace std::literals::chrono_literals;

int main()
{
  srand(time(NULL));

  std::vector<Moves*> moveslist;
  std::vector<DM> team;
  
  createMovelist(moveslist);
  createTeam(team);
  
  bool mp[nullProp];
  mp[0] = false;
  mp[1] = false;
  mp[2] = false;
  mp[3] = false;

  DM carl(100, 200, 200,200,200,200, 4);
  carl.addMove("1", mp, 3, 50);
  carl.addMove("2", mp, 5, 40);
  carl.addMove("3", mp, 7, 60);
  carl.addMove("4", mp, nullType, 80);

  DM carlos(100, 100, 100, 100, 100, 100, 6);
  carlos.addMove("1", mp, 2, 50);
  carlos.addMove("2", mp, 4, 0);
  carlos.addMove("3", mp, 6, 0);
  carlos.addMove("4", mp, 8, 0);

  DM carlito(100, 100, 100, 100, 100, 100, 8);
  carlito.addMove("1", mp, 2, 10);
  carlito.addMove("2", mp, 4, 30);
  carlito.addMove("3", mp, 6, 50);
  carlito.addMove("4", mp, 8, 70);

  std::vector<DM> p1Team;
  p1Team.push_back(carl);

  std::vector<DM> p2Team;
  p2Team.push_back(carlos);

  Player p1(p1Team);
  Player p2(p2Team);

  Game gamestate(p1, p2);

  std::cout << ((*p1.getTeam())[0].getHP()) << "\n";

  gamestate.takeTurn(attackOne, attackOne);

  std::cout << ((*p1.getTeam())[0].getHP()) << "\n";

  gamestate.takeTurn(attackOne, attackOne);

  std::cout << ((*p1.getTeam())[0].getHP()) << "\n";



  return 0;
}
