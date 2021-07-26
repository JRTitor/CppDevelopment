#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int a, b;

  cin >> a >> b;

  if (a == b) cout << a;

  else {
    if (a % b == 0 && a > b) cout << b;
    else if ( b % a == 0 && b > a) cout << a;

    else {
      while(a > 0 && b> 0) {
        if (a> b) a = a%b;
        else b = b%a;
      }
      cout << a+b;
    }
  }

  return 0;
}
