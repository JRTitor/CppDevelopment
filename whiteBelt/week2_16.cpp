#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> out;
  for(const auto& [key, value]: m) {
    out.insert(value);
  }
  return out;
}
