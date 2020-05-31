#include <string>
#include<vector>
#include <iostream>
#include <fstream>
#include <algorithm>

const int MAX_CHAR = 26;

using namespace std;

bool threevowels (string word) {
  std::string vowels = "aeiou";
  int occ = 0;

  for (char const &c: word) {
    if (vowels.find(c) != std::string::npos){
      occ++;
      if (occ == 3)
        return true;
    }
  }

  return false;
}

bool twice (string word) {
  for (int ind = 0; ind < (word.length() - 1); ind++) {
    if (word[ind] == word[ind+1])
      return true;
  }
  return false;
}

bool tofollow(string word) {
  string concat;
  std::vector<string> notgood;
  string str1 = "ab";
  string str2 = "cd";
  string str3 = "pq";
  string str4 = "xy";

  notgood.push_back(str1);
  notgood.push_back(str2);
  notgood.push_back(str3);
  notgood.push_back(str4);

  for (int ind = 0; ind < (word.length() - 1); ind++) {
    concat = word[ind];
    concat += word[ind+1];
    for (auto it = notgood.begin() ; it != notgood.end(); ++it){
    if (concat == *it)
      return false;
    }
  }
  return true;
}

bool contains(string word) {
  string concat;

  for (int ind = 0; ind < (word.length() - 1); ind++) {
    concat = word[ind];
    concat += word[ind+1];

    size_t pos = word.find(concat, ind + 2);
    if (pos != std::string::npos) {
      return true;
    }
  }
  return false;
}

bool sandwich(string word) {
  for (int ind = 0; ind < (word.length() - 1); ind++) {
    if (word[ind] == word[ind+2])
      return true;
  }
  return false;
}

int greatline (string word){
  if (threevowels(word) && twice(word) && tofollow(word)){
    // cout << word << '\n';
    return 1;
  }
  else
    return 0;
}

int greatline2 (string word){
  if (contains(word) && sandwich(word)){
    // cout << word << '\n';
    return 1;
  }
  else
    return 0;
}

int readfile (char * file) {
  string line;
  ifstream myfile;
  int good;
  int res;
  myfile.open (file);

  res = 0;
  good = 0;

  if (myfile.is_open())
  {
    if (myfile.is_open()){
      while (getline(myfile, line)){
        good = greatline2(line);
        res = res + good;
      }
      myfile.close();
    }
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
