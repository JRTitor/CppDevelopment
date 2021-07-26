#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  int sum = 0;
  cin >> n;

  vector<int> v(n);

  for (int& i: v) {
    cin >> i;
    sum += i;
  }

  vector<int> out;
  int cnt = 0;
  int avg = sum/n;

  for (int i = 0; i < n; i++) {
    if(v[i] > avg) {
      out.push_back(i);
    }
  }

  cout << out.size() << '\n';

  for(int i: out) {
    cout << i<<' ';
  }

  return 0;
}
