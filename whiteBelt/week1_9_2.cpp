#include <iostream>
#include <vector>
using namespace std;

int main() {
	unsigned long long inpt;
  long long i = 0 ;
  vector<int> v;
  cin >> inpt;
  if (inpt == 0) cout << 0;
  else {

    while (inpt > 0) {
		    v.push_back(inpt%2);
		     inpt = inpt/2;
		      ++i;
        }
        for (; i > -1; i--) {
          if (v.size() == i && v[i] == 0){
            continue;
          }
          cout << v[i];
        }
  }
  putchar('\n');
	return 0;
}
