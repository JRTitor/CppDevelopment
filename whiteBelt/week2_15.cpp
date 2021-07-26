#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  set<string> s;
  for (int i = 0; i < n; ++i) {
    string l;
    cin >> l;
    s.insert(l);
  }
  cout << s.size() << '\n';
  return 0;
}
