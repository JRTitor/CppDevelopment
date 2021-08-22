#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

template <typename T>
  string NumberToString ( T Number ){
     ostringstream ss;
     ss << Number;
     return ss.str();
  }


struct parts {
  int num ;
  char op ;
};

int main1() {
  int a;
  size_t b;
  cin >> a >> b;
  string s = '('+ to_string(a) +')';
  for (size_t i = 0; i < b; i++) {
    parts part;
    cin >>  part.op >> part.num;
    s = '(' + s + ' ' + part.op + ' ' + NumberToString(part.num) + ')';
  }
  cout << s << '\n';

  return 0;
}

int main2() {
  int a;
  size_t b;
  cin >> a >> b;
  string s =  to_string(a);
  for (size_t i = 0; i < b; i++) {
    parts part;
    cin >>  part.op >> part.num;
    if (part.op == '/' || part.op == '^' || part.op == '!') {
      s = '(' + s + ')' + ' ' + part.op + ' ' + NumberToString(part.num) ;
    }
    else s = s + ' ' + part.op + ' ' + NumberToString(part.num) ;
  }
  cout << s << '\n';

  return 0;
}

int main() {
  int a;
  size_t b;
  cin >> a >> b;
  string ss =  to_string(a);
  deque<string> exp;
  exp.push_back(ss);
  for (size_t i = 0; i < b; i++) {
    parts part;
    cin >>  part.op >> part.num;
    if (part.op == '/' || part.op == '^' || part.op == '!') {
      exp.push_front("(");
      exp.push_back(")");
    }
    exp.push_back(" ");
    exp.push_back(string(1, part.op));
    exp.push_back(" ");
    exp.push_back(NumberToString(part.num));
  }

  for (const string& s : exp) {
   cout << s;
 }
 cout << '\n';

  return 0;
}
