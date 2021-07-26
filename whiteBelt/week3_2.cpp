#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<string> v(n);

  for(string& i: v) cin >> i;

  sort(begin(v), end(v), [](const string& wo, const string wt) {
    return lexicographical_compare(begin(wo), end(wo), begin(wt), end(wt),[](char woC, char wtC) {
      return tolower(woC) < tolower(wtC);
    });
  });

  for(const string& i: v) cout << i <<' ';
  cout << '\n';

  return 0;
}
