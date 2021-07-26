#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
  vector<string> out;
  for(auto word: words) {
    if (IsPalindrom(word) && word.size() >= minLength) {
      out.push_back(word);
    }
  }
  return out;
}
