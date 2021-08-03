#include <iostream>

using namespace std;

int main() {
  size_t n, r;
  cin >> n >> r;

  uint64_t w, h, d, sum = 0;
  for (size_t i = 0; i < n; i++) {
    cin >> w >> h >> d;
    sum += w*h*d*r;
  }
  cout << sum << '\n';
  return 0;
}
