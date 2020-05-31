#include <string>
#include<vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int parseMap (string code){
  std::pair<int,int> coord;
  std::vector<pair<int,int>> houses;
  int uniq_house;

  uniq_house = 0;
  coord = std::make_pair (0,0);
  houses.push_back(coord);
  for (char const &c: code) {
    switch (c) {
      case '^':
        coord.second = coord.second + 1;
        break;
      case 'v':
        coord.second = coord.second - 1;
        break;
      case '<':
        coord.first = coord.first - 1;
        break;
      case '>':
        coord.first = coord.first + 1;
        break;
      default :
        cout << "Bug";
        exit(1);
    }
    houses.push_back(coord);
    // cout << coord.first << ',' << coord.second << '\n';
	}

  sort( houses.begin(), houses.end() );
  houses.erase( unique( houses.begin(), houses.end() ), houses.end() );
  uniq_house = houses.size();
  return uniq_house;
}

int parseMap2 (string code){
  std::pair<int,int> coord1;
  std::pair<int,int> coord2;

  std::vector<pair<int,int>> houses;
  int uniq_house;
  int cpt;

  cpt = 0;
  uniq_house = 0;
  coord1 = std::make_pair (0,0);
  coord2 = std::make_pair (0,0);

  auto coord = &coord1;
  houses.push_back(*coord);
  for (char const &c: code) {
    if ((cpt%2) == 0)
      coord = &coord1;
    else
      coord = &coord2;
    switch (c) {
  		case '^':
        (*coord).second = (*coord).second + 1;
        break;
      case 'v':
        (*coord).second = (*coord).second - 1;
        break;
      case '<':
        (*coord).first = (*coord).first - 1;
        break;
      case '>':
        (*coord).first = (*coord).first + 1;
        break;
      default :
        cout << "Bug";
        exit(1);
    }
    cpt++;
    houses.push_back(*coord);
    // cout << (*coord).first << ',' << (*coord).second << '\n';
	}

  sort( houses.begin(), houses.end() );
  houses.erase( unique( houses.begin(), houses.end() ), houses.end() );
  uniq_house = houses.size();
  return uniq_house;
}

int readfile (char * file) {
  string line;
  ifstream myfile;
  int res;
  myfile.open (file);

  res = 0;

  if (myfile.is_open())
  {
    getline(myfile, line);
    // cout << line << '\n';
    res = parseMap2(line);
    myfile.close();

  }

  else cout << "Unable to open file";

  return res;
}

int main(int argc, char * argv[]) {
  string code;
  cout << readfile(argv[1]) << '\n';
  // cout << parseFloors2 (code) << '\n';
  exit(0);
}
