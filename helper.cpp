#include "DM.h"
#include "Game.h"
#include "globals.h"
#include "Moves.h"
#include "Player.h"

#include <fstream>
#include <iostream>
#include <string>


void createTeam(std::vector<DM> newTeam)
{
  std::ifstream teamFile("team.mon");
  std::string monName;
  int hp, spd, def, spa, atk, sped, t1, t2, eva, crit, prec;
  
  while(!teamFile.eof())
  {
    std::getline(teamFile, monName, ',');
    teamFile >> hp;
    teamFile.ignore();
    teamFile >> spd;
    teamFile.ignore();
    teamFile >> def;
    teamFile.ignore();
    teamFile >> spa;
    teamFile.ignore();
    teamFile >> atk;
    teamFile.ignore();
    teamFile >> sped;
    teamFile.ignore();
    teamFile >> t1;
    teamFile.ignore();
    teamFile >> t2;
    teamFile.ignore();
    teamFile >> eva;
    teamFile.ignore();
    teamFile >> crit;
    teamFile.ignore();
    teamFile >> prec;
    teamFile.ignore();
    teamFile.ignore();
    std::cout << monName << " " << prec << "\n";
  }
}

void createMovelist(std::vector<Moves*> moveslist)
{
  std::ifstream moveFile("movelist.mon");
  std::string garbage = "";
  std::string moveName = "";
  int mt = static_cast<int>(nullType);
  int acc = 0;
  int crit = 10;
  int bp = 100;
  bool moveProps[4] = {false};
  
  while(!moveFile.eof())
  {
    for(int i = 0; i < nullProp; i++)
    {
      moveFile.ignore();
      moveFile >> moveProps[i];
    }
    
    std::getline(moveFile, garbage, '\"');
    std::getline(moveFile, moveName, '\"');
    moveFile.ignore();
    moveFile >> mt;
    moveFile.ignore();
    moveFile >> acc;
    moveFile.ignore();
    moveFile >> crit;
    moveFile.ignore();
    moveFile >> bp;
    moveFile.ignore();
    moveFile.ignore();
    Moves* newMove = new DamagingMoves(moveName, moveProps, mt, acc, crit, bp);
  }
}