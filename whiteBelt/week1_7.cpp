#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  string s;
  int sum = 0, i = 0, j = 0;
  cin >> s;
  for(char a: s){

    if (a == 'f') {
      ++sum;
      if (sum == 2)
        j = i;
    }
    ++i;
  }

  if (sum == 0) cout<< -2;
  else {
    if (sum == 1) cout << -1;
    else cout << j;
  }
  return 0;
}
