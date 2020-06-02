#include "turn_on.hpp"
#include "lib.hpp"

void TurnOn::changelights() {
  for (int i = getX1() ; i <= getX2(); i++){
    for (int j = getY1(); j <= getY2(); j++)
    lights[i][j] = true;
  }
}

void TurnOn::changebrighness() {
  for (int i = getX1() ; i <= getX2(); i++){
    for (int j = getY1(); j <= getY2(); j++)
    lights2[i][j] = lights2[i][j] + 1;
  }
}

