#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int q;
  string word1, word2;
  set<set<string>> syn;
  map<string, set<string>> dct;
  cin >> q;

  for(int i = 0; i < q; ++i) {
    string oper;
    cin >> oper;

    if(oper == "ADD") {
      cin >> word1 >>word2;
      set<string> words;
      words.insert(word1);
      words.insert(word2);
      dct[word1].insert({word2});
      dct[word2].insert({word1});
      syn.insert(words);
    }
    else if(oper == "COUNT") {
      string word;
      cin >> word;
      int amnt = 0;
      cout << dct[word].size() << '\n';
    }

    else if(oper == "CHECK") {
      cin >> word1 >>word2;
      set<string> words;
      words.insert(word1);
      words.insert(word2);
      if  (syn.count(words)) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    }
  }
  return 0;
}
