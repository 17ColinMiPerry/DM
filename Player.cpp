#include "Player.h"

Player::Player()
{
  ;
}

Player::Player(std::vector<DM> newTeam)
{
  team = newTeam;

  if (team.size() > 0)
    activeMon = team[0];
}

std::vector<DM>* Player::getTeam()
{
  return &team;
}

void Player::addTeamMember(DM member)
{
  if (team.size() >= TEAM_SIZE)
    return;

  team.push_back(member);
}

DM Player::getActiveMon()
{
  return activeMon;
}
