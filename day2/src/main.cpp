#include <string>
#include<vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// 2*l*w + 2*w*h + 2*h*l

std::vector<int> parseline (std::string& s){
  std::vector<int> result;
  size_t pos = 0;
  int i;
  char delimiter = 'x';
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
     token = s.substr(0, pos);
     i = stoi(token);
     result.push_back(i);
     s.erase(0, pos + 1);
  }
  token = s.substr(0, pos);
  i = stoi(token);
  result.push_back(i);
  return result;
}

int compute_square(std::vector<int> box) {
  std::vector<int> result;
  int l = box[0];
  int w = box[1];
  int h = box[2];
  int square = 0;

  square =  2*l*w + 2*w*h + 2*h*l;

  result.push_back(l*w);
  result.push_back(w*h);
  result.push_back(h*l);

  auto it = min_element(std::begin(result), std::end(result));
  square = square + *it;
  // cout << square << '\n';
  return square;
}

int compute_ribbon(std::vector<int> box) {
  int l = box[0];
  int w = box[1];
  int h = box[2];
  int feet = 0;

  auto it = min_element(std::begin(box), std::end(box));
  int min1 = *it;
  it = box.erase(it);
  it = min_element(std::begin(box), std::end(box));
  int min2 = *it;
  it = box.erase(it);

  // cout << min1 << ' ' << min2 << '\n';

  feet = min1 + min1 + min2 + min2;
  feet = feet + l * w * h;
  return feet;
}

int readfile (char * file) {
  string line;
  std::vector<int> box;
  int res;
  ifstream myfile;

  res = 0;
  myfile.open (file);
  if (myfile.is_open()){
    while (getline(myfile, line)){
      box = parseline(line);
      // res = res + compute_square(box);
      res = res + compute_ribbon(box);
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  return res;
}

int main(int argc, char * argv[]) {
  int square;
  cout << readfile(argv[1]) << '\n';
  exit(0);
}
