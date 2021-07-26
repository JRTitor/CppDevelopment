#include <iostream>

using namespace std;

int main() {
  double N, A, B, X, Y, P = -1;

  cin >> N >> A >>  B >> X >> Y;

  if (N > A) {
    P = N * (100 - X)/100;
  }
  if (N > B) {
    P = N * (100 - Y)/100;
  }

  if (P == -1) P = N;

  cout << P << '\n';

  return 0;
}
