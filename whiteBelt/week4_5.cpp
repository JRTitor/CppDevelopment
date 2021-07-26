#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  ifstream input("input.txt");
  char space;
  int n , m;
  input >> n;
  input.ignore(1);
  input >> m;

  for (int i = 0; i < n*m; ++i) {
    int num;
    input >> num;
    if ((i+1 )%m != 0) cout << setw(10) << fixed << num<< " ";
    else  cout << setw(10) << fixed << num;
    input.ignore(1);
    if ((i+1)%m == 0) cout << '\n';
  }

  return 0;
}
