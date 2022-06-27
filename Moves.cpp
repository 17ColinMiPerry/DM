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

  for (int i = 0; i < 3; i++)
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

int Moves::getMoveType()
{
  return moveType;
}

std::string Moves::getMoveName()
{
  return moveName;
}

bool* Moves::getMoveProperties()
{
  return moveProperties;
}

int Moves::getMoveAccuracy()
{
  return accuracy;
}

// Damaging Moves

DamagingMoves::DamagingMoves(std::string name, bool* mp, int mt, int acc,
                             int crit, int bp)
  :Moves(name, mp, mt, acc)
{
  basePower = bp;
  critCh = crit;
}


// Status Moves

StatusMoves::StatusMoves(std::string name, bool* mp, int mt, int acc)
  :Moves(name, mp, mt, acc)
{
  ;
}
