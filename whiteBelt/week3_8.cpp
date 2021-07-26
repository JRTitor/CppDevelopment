#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Incognizable {
public:
  Incognizable() {}
  Incognizable(const int& a) {
    fir = a;
  }
  Incognizable(const int& a, const int& b) {
    fir = a;
    sec = b;
  }

private:
  int fir;
  int sec;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
