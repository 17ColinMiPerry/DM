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
  Moves(const Moves& otherMove);
  virtual ~Moves();

  // Setters
  void setMoveType(int mt);
  void setMoveName(std::string name);
  void setMoveAccuracy(int acc);

  // Getters
  virtual int getBasePower();
  int getMoveType() const;
  std::string getMoveName() const;
  bool* getMoveProperties();
  int getMoveAccuracy() const;

  // Game Interaction

private:

  std::string moveName;

  // Move Attributes
  int accuracy;
  Types moveType;
  bool moveProperties[4];

};

// DAMAGING MOVES

class DamagingMoves: public Moves
{
public:
  DamagingMoves(std::string name, bool* mp, int mt = BASE_TYPE, int acc = BASE_ACCURACY,
                int critCh = BASE_CRIT, int bp = BASE_MOVE_POWER);
  DamagingMoves();

  void setBasePower(int bp);
  void setCritCh(int cc);

  int getBasePower();
  int getCritCh() const;
private:
  // these need setters and getters
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
