#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool IsPalindrom(string in) {
  string other;
  int size = in.size() - 1;
  for (int i = size; i > -1; i--) {
    other += in[i];
  }
  if (other != in )return false;

  return true;
}

int main() {

  string inpt;
  cin >> inpt;
  if (IsPalindrom(inpt)) cout << "true" << '\n';
  else cout << "false" << '\n';
  return 0;
}
