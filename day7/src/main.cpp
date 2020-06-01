#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <boost/algorithm/string.hpp>

using namespace std;

bool lights[1000][1000];
int lights2[1000][1000];

class Action
{
public:
  // Constructeurs

  //Accesseurs et mutateurs
  void setX(pair<int, int> x) {
    this->x = x;
  }

  void setY(pair<int, int> y) {
    this->y = y;
  }

  pair<int, int> getX() const {
    return this->x;
  }

  pair<int, int> getY() const {
    return this->y;
  }

  int getX1() {
    return getX().first;
  }

  int getX2() {
    return getY().first;
  }

  int getY1() {
    return getX().second;
  }

  int getY2() {
    return getY().second;
  }

  virtual void changelights();
  virtual void changebrighness();

protected:
  std::pair<int,int> x,y;
};

class Toggle : public Action {

  void changelights() {
    for (int i = getX1() ; i <= getX2(); i++){
      for (int j = getY1(); j <= getY2(); j++)
      lights[i][j] = !lights[i][j];
    }
  }

  void changebrighness() {
    for (int i = getX1() ; i <= getX2(); i++){
      for (int j = getY1(); j <= getY2(); j++)
      lights2[i][j] = lights2[i][j]+2;
    }
  }

};

class TurnOn : public Action {

  void changelights() {
    for (int i = getX1() ; i <= getX2(); i++){
      for (int j = getY1(); j <= getY2(); j++)
      lights[i][j] = true;
    }
  }

  void changebrighness() {
    for (int i = getX1() ; i <= getX2(); i++){
      for (int j = getY1(); j <= getY2(); j++)
      lights2[i][j] = lights2[i][j] + 1;
    }
  }

};


class TurnOff : public Action {

  void changelights() {
    for (int i = getX1() ; i <= getX2(); i++){
      for (int j = getY1(); j <= getY2(); j++)
      lights[i][j] = false;
    }
  }

  void changebrighness() {
    for (int i = getX1() ; i <= getX2(); i++){
      for (int j = getY1(); j <= getY2(); j++)
      lights2[i][j] = (lights2[i][j] == 0) ? 0 : lights2[i][j]-1;
    }
  }

};

void initialize() {
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++)
    lights[i][j] = false;
  }
}

void initialize2() {
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++)
    lights2[i][j] = 0;
  }
}

int count() {
  int res;
  res = 0;
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++){
      if (lights[i][j])
      res++;
    }
  }
  return res;
}

int count2() {
  int res;
  res = 0;
  for (int i = 0; i < 1000; i++){
    for (int j = 0; j < 1000; j++)
      res = res + lights2[i][j];
  }
  return res;
}

void computeAct (Action *act, vector<string> s1, vector<string> s2){
  pair<int,int> p1;
  pair<int,int> p2;

  p1 = make_pair(stoi(s1[0]), stoi(s1[1]));
  p2 = make_pair(stoi(s2[0]), stoi(s2[1]));

  act->setX(p1);
  act->setY(p2);

  // act->changelights();
  act->changebrighness();

}

void parseLine (string line) {
  vector<string> strs;
  vector<string> p1;
  vector<string> p2;

  boost::split(strs,line,boost::is_space());

  if (strs[0] == "toggle"){
    Toggle act;
    boost::split(p1,strs[1],boost::is_any_of(","));
    boost::split(p2,strs[3],boost::is_any_of(","));
    computeAct (&act, p1, p2);
  }
  else {
    if (strs[1] == "on"){
      TurnOn act;
      boost::split(p1,strs[2],boost::is_any_of(","));
      boost::split(p2,strs[4],boost::is_any_of(","));
      computeAct (&act, p1, p2);
    }
    else {
      if (strs[1] == "off"){
        TurnOff act;
        boost::split(p1,strs[2],boost::is_any_of(","));
        boost::split(p2,strs[4],boost::is_any_of(","));
        computeAct (&act, p1, p2);
      }
      else
      exit(1);
    }
  }
}

int readfile (char * file) {
  string line;
  ifstream myfile;
  int good;
  int res;
  myfile.open (file);

  res = 0;
  good = 0;

  if (myfile.is_open()) {
    if (myfile.is_open()) {
      while (getline(myfile, line))
      parseLine(line);
      myfile.close();
    }
  }
  else
  cout << "Unable to open file";
  //
  // res = count();
  res = count2();

  return res;
}

int main(int argc, char * argv[]) {
  // initialize();
  initialize2();
  cout << readfile(argv[1]) << '\n';
  // cout << parseFloors2 (code) << '\n';
  exit(0);
}
