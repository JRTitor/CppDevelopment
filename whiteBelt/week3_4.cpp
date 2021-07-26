#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    logName[year]= first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    logSec[year] = last_name;
  }
  string GetFullName(int year) {
    string name = getName(year, logName);
    string sec = getName(year, logSec);
    string full = name + " " + sec;
    if (name.size() == 0 && sec.size() == 0)  return "Incognito";
    if (name.size() == 0) return sec + " with unknown first name";
    if (sec.size() == 0) return name + " with unknown last name";
    return full;
}
private:

  string getName(int year, map<int, string>& names) {
    string name;

    for(const auto& item: names) {
      if(item.first <= year) name = item.second;
      else break;
    }
    return name;
  }
  map<int,string> logName;
  map<int,string> logSec;

};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
