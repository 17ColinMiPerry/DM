#ifndef PLAYER_H
#define PLAYER_H

#include "DM.h"
#include "globals.h"
#include <vector>

class Player{
public:
  Player();

  std::vector<DM> getTeam();
  void addTeamMember(DM member);
private:
  std::vector<DM> team;
};


#endif
