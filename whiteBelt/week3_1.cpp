#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int& i: v) {
    cin >> i;
  }
  sort(begin(v), end(v), [] (int one, int two){
    return abs(one) < abs(two);
  });

  for(const int& i: v) cout << i <<' ';
  cout << '\n';
  return 0;
}
