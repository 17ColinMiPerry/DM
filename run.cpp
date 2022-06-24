#include "DM.h"
#include <iostream>

int main()
{
  DM carl(200,200,200,200,200, 4);
  carl.addMove(100, 3, "jeff");
  carl.addMove(200, 5, "won");
  carl.addMove(300, 7, "song");
  carl.addMove(400, null, "rat");
  carl.addMove(500, 11, "bastard");
  carl.addMove(600000, 40, "crum");

  int i = carl.getMoves().size();

  for(int j = 0; j < i; j++)
  {
    std::cout << carl.getMoves()[j].getMoveType();
  }

  std::cout << carl.getSecondaryType();

  return 0;
}
