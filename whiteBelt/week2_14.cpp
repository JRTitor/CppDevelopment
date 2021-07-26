#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int q;
  map<int, vector<string>> busList;

  cin >> q;

  for(int i = 0; i < q; i++) {
    int NumStops;
    cin >> NumStops;
    vector<string> stops(NumStops);
    for(string& stop: stops) {
      cin >> stop;
    }
    int flag = 0, keep;
    for(const auto& [num, list]: busList) {
      if(list == stops) {
        keep = num;
        ++flag;
      }
    }
    if (flag) cout << "Already exists for " << keep <<'\n';
    else {
      int n = busList.size() + 1;
      busList[n] = stops;
      cout << "New bus " << n << '\n';
    }
  }
  return 0;
}
