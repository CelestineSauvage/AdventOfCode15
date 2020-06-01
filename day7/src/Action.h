#ifndef ACTION_H
#define ACTION_H

#include <iostream>
using namespace std;

class Action
{
  public:
  // Constructeurs
  // Action(std::pair<int,int> x, std::pair<int,int> y);

  //Accesseurs et mutateurs
  void setX(std::pair<int,int> x);
  void setY(std::pair<int,int> y);
  std::pair<int,int> getX() const;
  std::pair<int,int> getY() const;

  // Autres méthodes
  int getX1();
  int getX2();
  int getY1();
  int getY2();

  void changelights(bool **lights);

protected:
  std::pair<int,int> x,y;
};

class Toggle : public Action
{

};


#endif
