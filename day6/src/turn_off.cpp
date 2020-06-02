#include "turn_off.hpp"
#include "lib.hpp"

void TurnOff::changelights() {
  for (int i = getX1() ; i <= getX2(); i++){
    for (int j = getY1(); j <= getY2(); j++)
    lights[i][j] = false;
  }
}

void TurnOff::changebrighness() {
  for (int i = getX1() ; i <= getX2(); i++){
    for (int j = getY1(); j <= getY2(); j++)
    lights2[i][j] = (lights2[i][j] == 0) ? 0 : lights2[i][j]-1;
  }
}
