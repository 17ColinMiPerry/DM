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
  ;
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
  
  int count = 0;
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
    std::cout << newMove->getBasePower() << std::endl;
    count ++;
  }

}