#ifndef GLOBALS_H
#define GLOBALS_H


// DAEMON TYPING - NULL MUST ALWAYS BE LAST
enum Types{
  fire = 0,
  water = 1,
  air = 2,
  grass = 3,
  earth = 4,
  light = 5,
  shadow = 6,
  poison = 7,
  mech = 8,
  psionic = 9,
  null
};


enum BattleChoice{
  attackOne = 1,
  attackTwo = 2,
  attackThree = 3,
  attackFour = 4,
  benchOne = 5,
  benchTwo = 6
};

enum MoveProperties{
  priority = 0,
  status = 1,
  bypassAccuracy = 2
};

// CONSTANTS
const int BASE_CRIT = 10;
const int BASE_ACCURACY = 100;
const int BASE_MOVE_POWER = 0;

const int BASE_STAT = 100;

const int BASE_EVASION = 0;
const int BASE_CRITMOD = 0;
const int BASE_PRECISION = 100;

const Types BASE_TYPE = null;

const int TEAM_SIZE = 3;


#endif
