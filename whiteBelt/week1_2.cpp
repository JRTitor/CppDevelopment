#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<string> v;
  string input;

  for (int i = 0; i < 3; i++) {
    cin >> input;
    v.push_back(input);

  }

  sort(v.begin(), v.end());
  cout << v[0] << '\n';

  return 0;
}
