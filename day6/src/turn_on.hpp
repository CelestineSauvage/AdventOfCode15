#pragma once

#include "action.hpp"

class TurnOn : public Action {
  void changelights();
  void changebrighness();
};

