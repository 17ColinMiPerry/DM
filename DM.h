#ifndef DM_H
#define DM_H

#include <vector>
#include <string>
#include "globals.h"

// DAEMON MOVES
class Moves{
public:

  // Move Constructors and Destructors
  Moves();
  Moves(std::string name, int mt = BASE_TYPE, int critCh = BASE_CRIT, int acc = BASE_ACCURACY);
  virtual ~Moves();

  // Setters
  void setMoveType(int mt);
  void setMoveName(std::string name);

  // Getters
  int getMoveType();
  std::string getMoveName();
  virtual bool* getMoveProperties();

  // Game Interaction

private:

  std::string moveName;

  // Move Attributes *** MOVE CRITCH TO DMGING MOVES ***
  int critCh;
  int accuracy;
  Types moveType;
  bool moveProperties[3];

};

class DamagingMoves: public Moves
{
public:
  DamagingMoves(std::string name, int mt = BASE_TYPE, int critCh = BASE_CRIT,
                int acc = BASE_ACCURACY, int bp = BASE_MOVE_POWER);
private:
  int basePower;
};

// DAEMON
class DM
{
public:

  // Daemon Constructors
  DM();
  DM(int newSPD, int newDEF, int newSPA, int newATK, int newSPED, int t1, int t2 = BASE_TYPE,
     int eva = BASE_EVASION, int crit = BASE_CRIT, int prec = BASE_PRECISION);
  ~DM();

  // Setters
  void setPrimaryType(int type);
  void setSecondaryType(int type);

  void setSPD(int s);
  void setDEF(int d);
  void setSPATK(int s);
  void setATK(int a);
  void setSPED(int s);

  void addMove(std::string name, int mt = BASE_TYPE, int bp = BASE_MOVE_POWER,
               int critCh = BASE_CRIT, int acc = BASE_ACCURACY);

  // Getters
  int getPrimaryType();
  int getSecondaryType();

  int getSPD();
  int getDEF();
  int getSPATK();
  int getATK();
  int getSPED();

  std::vector<Moves*> getMoves();

private:

  // Daemon typing - secondaryType default null
  Types primaryType;
  Types secondaryType;

  // Vector of moves (size 4)
  std::vector<Moves*> moveSet;

  // Base Stats
  int spD;
  int def;
  int spAtk;
  int atk;
  int sped;

  // Base Battle Factors
  int evasion;
  int critMod;
  int precision;

};

#endif
