#ifndef PLAYER_H
#define PLAYER_H

#include "DM.h"
#include "globals.h"
#include <vector>

class Player{
public:
  Player();
  Player(std::vector<DM> newTeam);

  std::vector<DM>* getTeam();
  void addTeamMember(DM member);

  DM getActiveMon();
  DM* getActiveMonPtr();
  
private:
  std::vector<DM> team;
  DM activeMon;
};


#endif
