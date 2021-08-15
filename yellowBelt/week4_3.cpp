#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> SplitIntoWords(const string& s){
  vector<string> v;
  auto Begins = begin(s);
  auto Ends = end(s);
  for(;;) {
    auto it = find(Begins, Ends, ' ');
    v.push_back(string(Begins, it));
    if (it == Ends ) break;
    Begins = it + 1;
  }
  return v;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
