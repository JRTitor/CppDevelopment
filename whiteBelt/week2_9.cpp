 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  vector<int> q;
  int n;

  cin >> n;

  for(int i = 0; i < n; i++) {
    string cmd;
    int num;

    cin >> cmd;

    if( cmd == "WORRY") {
      cin >> num;
      q[num] = 1;
    }
    if(cmd == "QUIET") {
      cin >> num;
      q[num] = 0;
    }
    if( cmd ==  "COME") {
      cin >> num;
      int sz = q.size() + num;
      q.resize(sz, 0);
    }
    if( cmd ==  "WORRY_COUNT") {
      int wr = count(begin(q), end(q), 1);
      cout << wr << '\n';
    }
  }
  return 0;
}
