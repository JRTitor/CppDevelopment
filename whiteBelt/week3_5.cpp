#include <iostream>
#include <string>
#include <vector>
#include <map>

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
  string GetFullNameWithHistory(int year) {
    vector <string> Pnames = getPev(year, logName);
    vector <string> Psec =  getPev(year, logSec);
    string nm = getName(year, logName);
    string sc = getName(year, logSec);

    string full;
    if (nm.size() == 0 && sc.size() == 0) return "Incognito";
    if (sc.size() == 0) {
      full += nm;
      if (Pnames.size() > 1 || (Pnames.size() &&Pnames[0] != nm )) {
        full +=" (";
        if(Pnames[0] == nm) {
          for(int i = 1; i < Pnames.size(); ++i){
            full += Pnames[i];
            if( i < Pnames.size() - 1) full +=", ";
          }
        }
        else {
          for(int i = 0; i < Pnames.size(); ++i){
            full += Pnames[i];
            if( i < Pnames.size() - 1) full +=", ";
          }
        }
        full +=  ")";
      }


      full += " with unknown last name";
      return full;
    }
    if(nm.size() == 0) {
      full += sc;
      if(Psec.size() > 1 || (Psec.size() && Psec[0] != sc )) {
        full += " (" ;
        if(Psec[0] == sc) {
          for(int i = 1; i < Psec.size(); ++i){
            full += Psec[i];
            if( i < Psec.size() - 1) full +=", ";
          }
        }
        else {
          for(int i = 0; i < Psec.size(); ++i){
            full += Psec[i];
            if( i < Psec.size() - 1) full +=", ";
          }
        }

        full += ")";
      }
      full += " with unknown first name";
      return full;
    }

    full += nm;
    if (Pnames.size() > 1 || (Pnames.size() && Pnames[0] != nm)) {
      full +=" (";
      if(Pnames[0] == nm) {
        for(int i = 1; i < Pnames.size(); ++i){
          full += Pnames[i];
          if( i < Pnames.size() - 1) full +=", ";
        }
      }
      else {
        for(int i = 0; i < Pnames.size(); ++i){
          full += Pnames[i];
          if( i < Pnames.size() - 1) full +=", ";
        }
      }
      full +=  ")";
    }


    full += " ";
    full += sc;
    if(Psec.size() > 1 || (Psec.size() && Psec[0] != sc)) {
      full += " (" ;
      if(Psec[0] == sc) {
        for(int i = 1; i < Psec.size(); ++i){
          full += Psec[i];
          if( i < Psec.size() - 1) full +=", ";
        }
      }
      else {
        for(int i = 0; i < Psec.size(); ++i){
          full += Psec[i];
          if( i < Psec.size() - 1) full +=", ";
        }
      }
      full += ")";
    }


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

  string getPName(int year, map<int, string>& names) {
    string name;
    for(const auto& item: names) {
      if(item.first < year) name = item.second;
      else break;
    }
    return name;
  }

  vector<string> getPev(int year, map<int, string>& names) {
    vector<string> name;
    string ln = getPName(year, names);
    string prvs;
    for(const auto& item: names) {
      if(item.first < year && item.second != prvs) {
        name.insert(name.begin(), item.second);
        prvs = item.second;
      }
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
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
