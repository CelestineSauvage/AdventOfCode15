#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int parseFloors1 (string code){
  int sum;
  sum = 0;
  for (char const &c: code) {
		if (c == '(')
      sum++;
    else if (c == ')')
      sum--;
    else
      cout << "Bug";
	}
  return sum;
}

int parseFloors2 (string code){
  int sum;
  int ind;
  ind = 1;
  sum = 0;
  for (char const &c: code) {
		if (c == '(')
      sum++;
    else if (c == ')')
      sum--;
    else
      cout << "Bug";

    if (sum == -1)
      break;
    ind++;
	}
  return ind;
}

string readfile (char * file) {
  string line;
  string result;
  ifstream myfile;
  myfile.open (file);
  if (myfile.is_open())
  {
    getline (myfile,line);
    myfile.close();
  }

  else cout << "Unable to open file";

  return line;
}

int main(int argc, char * argv[]) {
  string code;
  code = readfile(argv[1]);
  cout << parseFloors2 (code) << '\n';
  exit(0);
}
