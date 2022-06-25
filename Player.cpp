#include "Player.h"

Player::Player()
{
  ;
}

std::vector<DM> Player::getTeam()
{
  return team;
}

void Player::addTeamMember(DM member)
{
  if (team.size() >= TEAM_SIZE)
    return;

  team.push_back(member);
}
