#include "Action.h"

using namespace std;

// Action::Action(pair<int, int> x,pair<int, int> y) : x(make_pair(0,0)), y(make_pair(0,0)) {}
Action::Action(pair<int, int> x,pair<int, int> y) : x(x), y(y) {}

void Action::setX(pair<int, int> x) {
  this->x = x;
}

void Action::setY(pair<int, int> y) {
  this->y = y;
}

pair<int, int> Action::getX() const {
  return this->x;
}

pair<int, int> Action::getY() const {
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
