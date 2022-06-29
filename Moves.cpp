#include "Moves.h"

// Move Constructors
Moves::Moves()
{
  ;
}

Moves::Moves(std::string name, bool* mp, int mt, int acc)
{
  moveName = name;
  moveType = static_cast<Types> (mt);

  accuracy = acc;

  for (int i = 0; i < nullProp; i++)
  {
    moveProperties[i] = mp[i];
  }
}


Moves::~Moves()
{
  ;
}

// Move Setters

void Moves::setMoveType(int mt)
{
  moveType = static_cast<Types>(mt);
}

void Moves::setMoveName(std::string name)
{
  moveName = name;
}

void Moves::setMoveAccuracy(int acc)
{
  accuracy = acc;
}


// Move Getters

int Moves::getMoveType() const
{
  return moveType;
}

std::string Moves::getMoveName() const
{
  return moveName;
}

bool* Moves::getMoveProperties()
{
  return moveProperties;
}

int Moves::getMoveAccuracy() const
{
  return accuracy;
}

int Moves::getBasePower()
{
  return 0;
}

// Damaging Moves

DamagingMoves::DamagingMoves(std::string name, bool* mp, int mt, int acc,
                             int crit, int bp)
  :Moves(name, mp, mt, acc)
{
  basePower = bp;
  critCh = crit;
}

DamagingMoves::DamagingMoves()
{

}

void DamagingMoves::setBasePower(int bp)
{
  basePower = bp;
}

void DamagingMoves::setCritCh(int cc)
{
  critCh = cc;
}


int DamagingMoves::getBasePower()
{
  return basePower;
}

int DamagingMoves::getCritCh() const
{
  return critCh;
}

// Status Moves

StatusMoves::StatusMoves(std::string name, bool* mp, int mt, int acc)
  :Moves(name, mp, mt, acc)
{
  ;
}
