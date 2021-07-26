#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct date {
  int day;
  int month;
  int year;
};

struct student {
  string name;
  string sec;
  date data;
};

int main() {
  int n;
  cin >> n;
  vector <student> v(n);
  for(int i = 0; i < n; ++i ){
    cin >> v[i].name >> v[i].sec >> v[i].data.day >> v[i].data.month >> v[i].data.year;
  }
  int m;
  cin >> m;
  for(int i = 0; i < m; ++i) {
    string request;
    int num;
    cin >> request >> num;
    if (request == "name" && num <= v.size() && num > 0) {

      cout << v[num-1].name << " " << v[num-1].sec << '\n';
    }
    else if (request == "date" && num <= v.size() && num > 0) {
      cout << v[num-1].data.day << "." << v[num-1].data.month << "." << v[num-1].data.year <<'\n';
    }
    else {
      cout << "bad request" << '\n';
    }
  }
  return 0;
}
