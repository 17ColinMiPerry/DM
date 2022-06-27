#ifndef MOVES_H
#define MOVES_H

#include <vector>
#include <string>
#include "globals.h"

// DAEMON MOVES
class Moves{
public:

  // Move Constructors and Destructors
  Moves();
  Moves(std::string name, bool* mp, int mt = BASE_TYPE, int acc = BASE_ACCURACY);
  virtual ~Moves();

  // Setters
  void setMoveType(int mt);
  void setMoveName(std::string name);
  void setMoveAccuracy(int acc);

  // Getters
  int getMoveType();
  std::string getMoveName();
  bool* getMoveProperties();
  int getMoveAccuracy();
  
  // Game Interaction

private:

  std::string moveName;

  // Move Attributes
  int accuracy;
  Types moveType;
  bool moveProperties[3];

};

// DAMAGING MOVES

class DamagingMoves: public Moves
{
public:
  DamagingMoves(std::string name, bool* mp, int mt = BASE_TYPE, int acc = BASE_ACCURACY,
                int critCh = BASE_CRIT, int bp = BASE_MOVE_POWER);
private:
  int basePower;
  int critCh;
};


// STATUS MOVES

class StatusMoves: public Moves
{
public:
  StatusMoves(std::string name, bool* mp, int mt = BASE_TYPE, int acc = BASE_ACCURACY);
};

#endif
