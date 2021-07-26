#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounters(const string& str) {
  map<char, int> counter;
  for(const char& a: str) {
    ++counter[a];
  }
  return counter;
}

int main() {
  string first, second;
  int N;

  cin >> N;
  for(int i = 0; i < N; i++ ) {
    cin >> first >> second;
    map<char, int> fdic, sdic;

    fdic = BuildCharCounters(first);
    sdic = BuildCharCounters(second);

    if(fdic == sdic) {
      cout << "YES" << '\n';
    }else cout << "NO" << '\n';
  }
  return 0 ;
}
