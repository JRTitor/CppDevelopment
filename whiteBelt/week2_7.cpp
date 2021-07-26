#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
  int n = v.size();
  vector<int> out;
  for (int i = 0; i < n ; ++i) {

    out.push_back(v[n - 1 - i]);
  }
  return out;
}
