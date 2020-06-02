#pragma once

#include <string>

class Action
{
public:
  void setX(std::pair<int, int> x);
  void setY(std::pair<int, int> y);

  std::pair<int, int> getX() const;
  std::pair<int, int> getY() const;

  int getX1();
  int getX2();
  int getY1();
  int getY2();

  virtual void changelights() = 0;
  virtual void changebrighness() = 0;

protected:
  std::pair<int,int> x,y;
};

