#include <vector>
#include <string>

// DAEMON TYPING - NULL MUST ALWAYS BE LAST
  enum Types{
    fire = 0,
    water = 1,
    air = 2,
    grass = 3,
    earth = 4,
    light = 5,
    shadow = 6,
    poison = 7,
    mech = 8,
    psionic = 9,
    null
  };

// DAEMON MOVES
class Moves{
public:

  //Move Constructors
  Moves();
  Moves(int bp, int mt, std::string name, int critMod = 1, int acc = 1);

  // Setters
  void setBasePower(int bp);
  void setMoveType(int mt);
  void setMoveName(std::string name);

  // Getters
  int getBasePower();
  int getMoveType();
  std::string getMoveName();
private:

  std::string moveName;

  // Move Attributes
  int basePower;
  int critModifier;
  int accuracy;
  Types moveType;

};

// DAEMON
class DM
{
public:

  // Daemon Constructors
  DM();
  DM(int newSPD, int newDEF, int newSPA, int newATK, int newSPED, int t1, int t2 = null, int eva = 1, int crit = 1, int prec = 1);

  // Setters
  void setPrimaryType(int type);
  void setSecondaryType(int type);

  void setSPD(int s);
  void setDEF(int d);
  void setSPATK(int s);
  void setATK(int a);
  void setSPED(int s);

  void addMove(int bp, int mt, std::string name);

  // Getters
  int getPrimaryType();
  int getSecondaryType();

  int getSPD();
  int getDEF();
  int getSPATK();
  int getATK();
  int getSPED();

  std::vector<Moves> getMoves();

private:

  // Daemon typing - secondaryType default null
  Types primaryType;
  Types secondaryType;

  // Vector of moves (size 4)
  std::vector<Moves> moveSet;

  // Base Stats
  int spD;
  int def;
  int spAtk;
  int atk;
  int sped;

  // Base Battle Factors
  int evasion;
  int critCh;
  int precision;

};
