#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {;
  vector<int> tmp;
  int size = v.size() - 1;
    for (int i = size; i > -1; i--) {
        tmp.push_back(v[i]);
    }
    v.clear();
    v = tmp;
}
