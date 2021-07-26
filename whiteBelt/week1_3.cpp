#include <cmath>
#include <iostream>

using namespace std;

int main() {

  double a, b, c, d;

  cin>>a >> b >>c;

  double x[2];

  d = (b*b - 4 * a * c);

  if (d > 0 && a!= 0){
    x[0] = (-1* b + sqrt(d))/(2*a);
    x[1] = (-1* b - sqrt(d))/(2*a);
    cout << x[0]<<' ' << x[1]<< endl;
  }else if (d == 0  && a!= 0) {
    cout << -1*b/(2*a)<<endl;
  }
  else if (d > 0 && a == 0)
    cout << -1*c/b << '\n';

  return 0;
}
