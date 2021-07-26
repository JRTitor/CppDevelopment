#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person {
public:
  Person(const string& name, const string& secn, const int& year) {
    birthd = year;
    logName[year] = name;
    logSec[year] = secn;
  }

  void ChangeFirstName(const int& year, const string& first_name) {
    if (year < birthd) return;
    logName[year]= first_name;
  }
  void ChangeLastName(const int& year, const string& last_name) {
    if (year < birthd) return;
    logSec[year] = last_name;
  }
  string GetFullName(const int& year) const{
    if (year < birthd) return "No person";
    string name = getName(year, logName);
    string sec = getName(year, logSec);
    string full = name + " " + sec;
    if (name.size() == 0 && sec.size() == 0)  return "Incognito";
    if (name.size() == 0) return sec + " with unknown first name";
    if (sec.size() == 0) return name + " with unknown last name";
    return full;
  }
  string GetFullNameWithHistory(const int& year) const{
    if (year < birthd) return "No person";
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
  string getName(const int& year, const map<int, string>& names) const{
    string name;
    for(const auto& item: names) {
      if(item.first <= year) name = item.second;
      else break;
    }
    return name;
  }

  string getPName(const int& year, const map<int, string>& names) const{
    string name;
    for(const auto& item: names) {
      if(item.first < year) name = item.second;
      else break;
    }
    return name;
  }

  vector<string> getPev(const int& year, const map<int, string>& names) const{
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
  int birthd;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
