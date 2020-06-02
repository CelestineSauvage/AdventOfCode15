#include "action.hpp"

void Action::setX(std::pair<int, int> x) {
  this->x = x;
}

void Action::setY(std::pair<int, int> y) {
  this->y = y;
}

std::pair<int, int> Action::getX() const {
  return this->x;
}

std::pair<int, int> Action::getY() const {
  return this->y;
}

int Action::getX1() {
  return getX().first;
}

int Action::getX2() {
  return getY().first;
}

int Action::getY1() {
  return getX().second;
}

int Action::getY2() {
  return getY().second;
}
