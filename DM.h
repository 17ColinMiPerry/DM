#ifndef DM_H
#define DM_H

#include <vector>
#include <string>
#include "globals.h"
#include "Moves.h"



// DAEMON
class DM
{
public:

  // Daemon Constructors
  DM();
  DM(int hp, int newSPD, int newDEF, int newSPA, int newATK, int newSPED, int t1, int t2 = BASE_TYPE,
     int eva = BASE_EVASION, int crit = BASE_CRIT, int prec = BASE_PRECISION);
  DM(const DM& otherDM);
  ~DM();

  DM& operator=(const DM& otherDM);


  // Setters
  void setPrimaryType(int type);
  void setSecondaryType(int type);

  void setHP(int hp);
  void setSPD(int s);
  void setDEF(int d);
  void setSPATK(int s);
  void setATK(int a);
  void setSPED(int s);

  void addMove(std::string name, bool* mp, int mt = BASE_TYPE, int critCh = BASE_CRIT,
               int acc = BASE_ACCURACY, int bp = BASE_MOVE_POWER);

  // Getters
  int getPrimaryType() const;
  int getSecondaryType() const;

  int getHP() const;
  int getSPD() const;
  int getDEF() const;
  int getSPATK() const;
  int getATK() const;
  int getSPED() const;

  std::vector<Moves*> getMoves() const;

private:

  // Daemon typing - secondaryType default null
  Types primaryType;
  Types secondaryType;

  // Vector of moves (size 4)
  std::vector<Moves*> moveSet;

  // Base Stats
  int hitpoints;
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
