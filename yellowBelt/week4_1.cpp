#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers){
  auto it = find_if(
    begin(numbers), end(numbers), [](const int& num){
      return num < 0;
    });
    bool first = true;
     while(it != begin(numbers)){
       --it;
      if (!first){
        cout << ' ';
      }
      first = false;
      cout << *it;
    }
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
