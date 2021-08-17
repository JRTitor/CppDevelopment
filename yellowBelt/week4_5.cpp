#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<< (ostream&  os, const vector<T>& cont) {
  bool first = true;
  for (auto it: cont) {
    if ( first) {
      os << it;
      first = false;
    }else {
      os <<  ' ' << it;
    }
  }
  return os;
}

void MakeAllTransfers(vector<int>& v, const int&  n) {
  for (size_t i = 1; i <= n; i++) {
     v.push_back(i);
  }
  vector<vector<int>> out;
  do{
    out.insert(begin(out), {begin(v), end(v)});
  }while (next_permutation(begin(v), end(v)));
  for(auto item: out) {
    cout << item << '\n';
  }
}

int main() {
  int n;
  cin  >> n;
  vector<int> v;
  MakeAllTransfers(v, n);

  return 0;
}
