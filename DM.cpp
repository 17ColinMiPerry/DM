#include "DM.h"
#include "Moves.h"

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

  int evasion = 1;
  int critMod = 1;
  int precision = 1;
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

  evasion = eva;
  critMod = crit;
  precision = prec;
}

DM::~DM()
{
  for (int i = 0; i < moveSet.size(); i++)
  {
    delete moveSet[i];
  }
}

// DM Move Management
void DM::addMove(std::string name, bool* mp, int mt, int crit, int acc, int bp)
{
  if (moveSet.size() >= 4)
    return;
    if (mt > null || mt < fire)
    return;

  Moves* newMove;

  // create logic for move properties using the bool array
  if (!mp[static_cast<int>(status)])
    newMove = new DamagingMoves(name, mp, mt, acc, crit, bp);
  if (mp[static_cast<int>(status)])
    newMove = new StatusMoves(name, mp, mt, acc);


  moveSet.push_back(newMove);

}

std::vector<Moves*> DM::getMoves()
{
    return moveSet;
}
