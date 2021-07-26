#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
  int q, cnt = 1;
  cin >> q;
  map<set<string>,int> stops;

  for(int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    set<string> line;
    for (int j = 0; j < k; ++j) {
      string stop;
      cin >> stop;
      line.insert(stop);
    }
    if(stops.count(line)) cout << "Already exists for " << stops[line] << '\n';
    else {
      stops[line] = cnt;
      cout << "New bus "<<  cnt<< '\n';
      cnt++;
    }
  }
  return 0;
}
