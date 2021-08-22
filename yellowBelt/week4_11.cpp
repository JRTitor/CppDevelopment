#include <iostream>
#include <string>
#include <map>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
  auto iter_after = names.upper_bound(year);
  string name;
  if (iter_after != names.begin()) {
    name = (--iter_after)->second;
  }
  return name;
}


class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    firstname[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    secondname[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    // с помощью двоичного поиска
    const string first_name = FindNameByYear(firstname, year);
    const string last_name = FindNameByYear(secondname, year);
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    }
    else if (first_name.empty()) {
      return last_name + " with unknown first name";
    }
    else if (last_name.empty()) {
      return first_name + " with unknown last name";
    }
    else {
      return first_name + " " + last_name;
    }
  }
private:
  // приватные поля
  map<int, string> firstname;
  map<int, string> secondname;
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
