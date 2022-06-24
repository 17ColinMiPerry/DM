#include "DM.h"

// DM Getters
int DM::getPrimaryType()
{
  return primaryType;
}

int DM::getSecondaryType()
{
  return secondaryType;
}

int DM::getSPD()
{
  return spD;
}

int DM::getDEF()
{
  return def;
}

int DM::getSPATK()
{
  return spAtk;
}

int DM::getATK()
{
  return atk;
}

int DM::getSPED()
{
  return sped;
}


// DM Setters
void DM::setPrimaryType(int type)
{
  primaryType = static_cast<Types>(type);
}

void DM::setSecondaryType(int type)
{
  secondaryType = static_cast<Types>(type);
}

void DM::setSPD(int s)
{
  spD = s;
}

void DM::setDEF(int d)
{
  def = d;
}

void DM::setSPATK(int s)
{
  spAtk = s;
}

void DM::setATK(int a)
{
  atk = a;
}

void DM::setSPED(int s)
{
  sped = s;
}


// DM Constructors
DM::DM()
{
  primaryType = null;
  secondaryType = null;

  spD = 0;
  def = 0;
  spAtk = 0;
  atk = 0;
  sped = 0;
}

DM::DM(int newSPD, int newDEF, int newSPA, int newATK, int newSPED, int t1, int t2, int eva, int crit, int prec)
{
  primaryType = static_cast<Types>(t1);
  secondaryType = static_cast<Types>(t2);

  spD = newSPD;
  def = newDEF;
  spAtk = newSPA;
  atk = newATK;
  sped = newSPED;

  evasion = 1;
  critCh = 1;
  precision = 1;
}


// DM Move Management
void DM::addMove(int bp, int mt, std::string name)
{
  if (moveSet.size() >= 4)
    return;
    if (mt > null || mt < fire)
    return;

    Moves newMove(bp, mt, name);

    moveSet.push_back(newMove);
}

std::vector<Moves> DM::getMoves()
{
    return moveSet;
}


// Move Constructors
Moves::Moves()
{
  ;
}

Moves::Moves(int bp, int mt, std::string name, int critMod, int acc)
{
  moveName = name;
  basePower = bp;
  moveType = static_cast<Types> (mt);

  critModifier = critMod;
  accuracy = acc;
}


// Move Setters
void Moves::setBasePower(int bp)
{
  basePower = bp;
}

void Moves::setMoveType(int mt)
{
  moveType = static_cast<Types>(mt);
}

void Moves::setMoveName(std::string name)
{
  moveName = name;
}


// Move Getters
int Moves::getBasePower()
{
  return basePower;
}

int Moves::getMoveType()
{
  return moveType;
}

std::string Moves::getMoveName()
{
  return moveName;
}
