#include "DM.h"
#include "Player.h"
#include <iostream>

int main()
{
  DM carl(200,200,200,200,200, 4);
  carl.addMove("jeff", 3, 20);
  carl.addMove("won", 5, 40);
  carl.addMove("song", 7);
  carl.addMove("rat", null, 10);


  int i = carl.getMoves().size();

  for(int j = 0; j < i; j++)
  {
    std::cout << carl.getMoves()[j].getBasePower() << "\n";
  }


  return 0;
}
