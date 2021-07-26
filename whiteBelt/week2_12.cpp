#include <iostream>
#include <map>
#include <string>

using namespace std;

void printCntry(const map<string, string>& m) {
    for (const auto& item : m) {
        cout << item.first << "/" << item.second << " ";
    }
    cout << '\n';
}

int main() {
  int q;
  map<string, string> countrCap;
  cin >> q;
  for(int i = 0; i < q; i++) {
    string country, new_capital, old_country_name, new_country_name;
    string inpt;
    cin >> inpt;

    if (inpt == "CHANGE_CAPITAL") {

      cin >> country >> new_capital;
      if ( countrCap[country] == "" ) {
        cout << "Introduce new country " << country << " with capital " << new_capital << '\n';
        countrCap.erase(country);
      }
      else if (new_capital != countrCap[country]){
        cout << "Country " << country << " has changed its capital from " << countrCap[country]
        << " to " << new_capital << '\n';
      }
      else if (new_capital == countrCap[country]) {
        cout << "Country " << country << " hasn't changed its capital" << '\n';
      }
      countrCap[country] = new_capital;
    }


    else if  (inpt == "RENAME") {
      cin >> old_country_name >> new_country_name;
      if (countrCap.count(new_country_name) || old_country_name == new_country_name) {
        cout << "Incorrect rename, skip" << '\n';
      }
      else if (countrCap[old_country_name] == ""){
        cout << "Incorrect rename, skip" << '\n';
        countrCap.erase(old_country_name);
      }
      else {
        cout << "Country " << old_country_name << " with capital " << countrCap[old_country_name] <<
        " has been renamed to " << new_country_name << '\n';
        countrCap[new_country_name] = countrCap[old_country_name];
        countrCap.erase(old_country_name);
       }
    }


    else if (inpt == "ABOUT") {
      cin >> country;
      if ( countrCap[country] != "" ){
        cout << "Country " << country << " has capital " << countrCap[country] << '\n';
      }
      else {
        cout << "Country " << country << " doesn't exist" <<'\n';
        countrCap.erase(country);
      }
    }


    else if (inpt == "DUMP") {
      if (countrCap.size() == 0) {
        cout << "There are no countries in the world" <<'\n';
      }
      else {
        printCntry(countrCap);
      }
    }
  }
  return 0;
}
