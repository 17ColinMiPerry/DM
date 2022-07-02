#include "DM.h"
#include "Moves.h"
#include <iostream>

// DM Getters
int DM::getPrimaryType() const
{
  return primaryType;
}

int DM::getSecondaryType() const
{
  return secondaryType;
}

int DM::getHP() const
{
  return hitpoints;
}

int DM::getSPD() const
{
  return spD;
}

int DM::getDEF() const
{
  return def;
}

int DM::getSPATK() const
{
  return spAtk;
}

int DM::getATK() const
{
  return atk;
}

int DM::getSPED() const
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

void DM::setHP(int hp)
{
  hitpoints = hp;
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
  primaryType = nullType;
  secondaryType = nullType;

  spD = 0;
  def = 0;
  spAtk = 0;
  atk = 0;
  sped = 0;

  int evasion = 1;
  int critMod = 1;
  int precision = 1;
}

DM::DM(int hp, int newSPD, int newDEF, int newSPA, int newATK, int newSPED, int t1, int t2, int eva, int crit, int prec)
{
  primaryType = static_cast<Types>(t1);
  secondaryType = static_cast<Types>(t2);

  hitpoints = hp;
  spD = newSPD;
  def = newDEF;
  spAtk = newSPA;
  atk = newATK;
  sped = newSPED;

  evasion = eva;
  critMod = crit;
  precision = prec;
}

DM::DM(const DM& otherDM)
{
  int moveCount = otherDM.getMoves().size();

  Moves* newMove;

  primaryType = static_cast<Types> (otherDM.getPrimaryType());
  secondaryType = static_cast<Types> (otherDM.getSecondaryType());

  hitpoints = otherDM.getHP();
  spD = otherDM.getSPD();
  def = otherDM.getDEF();
  spAtk = otherDM.getSPATK();
  atk = otherDM.getATK();
  sped = otherDM.getSPED();

  // need to add battle factors

  // add logic for copying other move types

  for (int i = 0; i < moveCount; i++)
  {
    newMove = new DamagingMoves(otherDM.getMoves()[i]->getMoveName(), otherDM.getMoves()[i]->getMoveProperties(),
                                otherDM.getMoves()[i]->getMoveType(), otherDM.getMoves()[i]->getMoveAccuracy(),
                                otherDM.getMoves()[i]->getCritCh(),otherDM.getMoves()[i]->getBasePower());
    moveSet.push_back(newMove);
  }
}

DM::~DM()
{
  for (int i = 0; i < moveSet.size(); i++)
  {
    delete moveSet[i];
  }
}

// add battle factors and logic for various move types
DM& DM::operator=(const DM& otherDM)
{
  primaryType = static_cast<Types> (otherDM.getPrimaryType());
  secondaryType = static_cast<Types> (otherDM.getSecondaryType());

  hitpoints = otherDM.getHP();
  spD = otherDM.getSPD();
  def = otherDM.getDEF();
  spAtk = otherDM.getSPATK();
  atk = otherDM.getATK();
  sped = otherDM.getSPED();

  return *this;
}

// DM Move Management
void DM::addMove(std::string name, bool* mp, int mt, int crit, int acc, int bp)
{
  if (moveSet.size() >= 4)
    return;
  if (mt > nullType || mt < fire)
    return;

  Moves* newMove;

  // create logic for move properties using the bool array
  if (!mp[static_cast<int>(status)])
    newMove = new DamagingMoves(name, mp, mt, acc, crit);
  if (mp[static_cast<int>(status)])
    newMove = new StatusMoves(name, mp, mt, acc);

  moveSet.push_back(newMove);

}

std::vector<Moves*> DM::getMoves() const
{
    return moveSet;
}
