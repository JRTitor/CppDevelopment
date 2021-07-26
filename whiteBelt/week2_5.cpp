#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destinaton) {

  for(auto i: source) {
    destinaton.push_back(i);
  }
  source.clear();
}
