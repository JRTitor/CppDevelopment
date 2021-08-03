#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (size_t i = 0; i < n; i++) {
    cin >> v[i];
    sum+= v[i];
  }
  int avg = sum/n;
  int cnt = 0;
  vector<int> out;
  for (size_t i = 0; i < n; i++) {
    if(v[i] > avg) {
      ++cnt;
      out.push_back(i);
    }
  }
  cout<< cnt << '\n';
  for (size_t i = 0; i < out.size(); i++) {
    cout << out[i];
    if(i + 1 < out.size()) cout << ' ';
  }

  return 0;
}
