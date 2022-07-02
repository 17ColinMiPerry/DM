#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>

// DAEMON TYPING - NULL MUST ALWAYS BE LAST
enum Types{
  fire = 0,
  water = 1,
  air = 2,
  grass = 3,
  earth = 4,
  holy = 5,
  abyssal = 6,
  poison = 7,
  mech = 8,
  psionic = 9,
  electric = 10,
  sound = 11,
  ice = 12,
  bug = 13,
  nullType
};


enum BattleChoice{
  attackOne = 1,
  attackTwo = 2,
  attackThree = 3,
  attackFour = 4,
  benchOne = 5,
  benchTwo = 6
};

enum MoveProps{
  priority = 0,
  status = 1,
  bypassAccuracy = 2,
  phys = 3,
  nullProp
};

// CONSTANTS
const int BASE_CRIT = 10;
const int BASE_ACCURACY = 100;
const int BASE_MOVE_POWER = 100;

const int BASE_STAT = 100;

const int BASE_EVASION = 0;
const int BASE_CRITMOD = 0;
const int BASE_PRECISION = 100;

const Types BASE_TYPE = nullType;

const int TEAM_SIZE = 3;


#endif
