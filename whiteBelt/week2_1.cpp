#include <iostream>

using namespace std;

int Factorial(int num) {
  int sum = 1;
  while (num> 1 ){
    sum *=  num;
    --num;
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  int inpt;

  cin >> inpt;
  if (inpt > 1) {
    cout << Factorial(inpt);
  }else cout << 1;
  return 0;
}
