#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void printBuses (const vector<string>& buses) {
  for(const string& item: buses) {
    cout << item << " " ;
  }
}

void printBusesName (const vector<string>& buses, const string& nameStop, const string& wrong) {
  cout << "Stop "<< nameStop<<":";
  for(const string& item: buses) {
    if (item != wrong)
      cout << " " << item;
  }
}

int main() {
  int q;
  map<string, vector<string>> busList;
  map<string, vector<string>> stopList;

  cin >> q;

  for(int i = 0; i < q; i++) {
    string oper;
    cin >> oper;

    if (oper == "NEW_BUS") {
      string bus;
      int stopsQ;
      cin >> bus;
      cin >> stopsQ;
      for (int j = 0; j < stopsQ; j++) {
        string stopName;
        cin >> stopName;
        busList[bus].push_back(stopName);
        vector<string> buses;
        buses.push_back(bus);
        if(stopList[stopName].size()) {
          stopList[stopName].insert(end(stopList[stopName]), begin(buses), end(buses));
        }
        else stopList[stopName] = buses;
      }
    }

    else if (oper == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      if (stopList[stop].size() > 0) {
        for (const auto& item : stopList) {
            if (item.first == stop) {
                for (string bs : item.second) {
                    cout << bs << " ";
                }
                cout << '\n';
            }
        }
      }
      else {
        cout << "No stop" <<'\n';
        stopList.erase(stop);
      }
    }


    else if (oper == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      if (busList[bus].size()) {
        for (const string& stop: busList[bus]) {
          if (stopList[stop].size() > 1) {
            printBusesName(stopList[stop], stop, bus);
            cout <<'\n';
          }
          else cout << "Stop " <<stop << ":" << " no interchange" <<'\n';
        }
      }
      else {
        busList.erase(bus);
        cout << "No bus" << '\n';
      }
    }


    else if (oper == "ALL_BUSES") {
      if (!busList.size()) {
        cout << "No buses" << '\n';
      }
      else {
        for (const auto& [buss, stp] : busList) {
          cout <<"Bus " << buss << ":";
          for (string s: stp) {
            cout << " " << s;
          }
          cout << '\n';
        }
      }

    }
  }
  return 0;
}
