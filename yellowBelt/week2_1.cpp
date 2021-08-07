#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string cmd;
  is >> cmd;
  if (cmd == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stopCnt = 0;
    is >> stopCnt;
    q.stops.resize(stopCnt);
    for(auto& stop: q.stops){
      is >> stop;
    }
  }
  if (cmd == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }
  if (cmd == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  if (cmd == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }
  return is;
}


struct BusesForStopResponse {
// Наполните полями эту структуру
  string stop;
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
// � еализуйте эту функцию
  if(r.buses.size()) {
    bool first = true;
    for(const auto& bus: r.buses) {
      if(first){
        os << bus;
        first = false;
      }
      else os << ' ' << bus;
    }
  }else os << "No bus";
  return os;
}

struct StopsForBusResponse {
  string bus;
  vector<string> stops;
  map<string, BusesForStopResponse> busesForStop;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
// � еализуйте эту функцию
  if(r.stops.size()) {
    bool first = true;
    for(const auto& stop: r.stops) {
      bool firstBus = true;
      if(!first) {
        os << '\n';
      }
      first = false;
      os << "Stop " << stop<<':';
      if(r.busesForStop.at(stop).buses.size() > 1) {
        for(const string& busForStop: r.busesForStop.at(stop).buses){
          if(!firstBus){
            os << " ";
          }
          firstBus = false;
          if(r.bus != busForStop) {
            os << busForStop;
          }
        }
      }else os << "No interchange";
    }
  }else os << "No stop";

  return os;
}

struct AllBusesResponse {
// Наполните полями эту структуру
  map<string, vector<string>> bsList;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
// � еализуйте эту функцию
  if(r.bsList.empty()){
    os << "No buses";
  }
  else{
    bool firstbus = true;
    for(const auto&[bus, stops]: r.bsList) {
      bool firstStop = true;
      if(!firstbus) {
        os << '\n';
      }
      firstbus = false;
      os << "Bus "<< bus<<": ";
      if(stops.size() > 1){
        for(const string& stop: stops){
          if(!firstStop){
            os << ' ';
          }
          firstStop = false;
          os << stop;
        }
      }
    }
  }
  return os;
}

class BusManager {
private:
  map<string,vector<string>> busStoplist;
  map<string,vector<string>> stopBuslist;
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    busStoplist[bus] = stops;
    for(const string& stop: stops) {
      stopBuslist[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // � еализуйте этот метод

    if(stopBuslist.count(stop) > 0) {
      return {stop, stopBuslist.at(stop)};
    }
    else return{};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
  // � еализуйте этот метод
  vector<string> stops;
    if(busStoplist.count(bus) > 0) {
      stops = busStoplist.at(bus);
    }
    map<string, BusesForStopResponse> busesFstop;
    for(const string& stop: stops) {
      busesFstop[stop] = GetBusesForStop(stop);
    }

    return{bus, stops, busesFstop};
  }

  AllBusesResponse GetAllBuses() const {
    if (busStoplist.empty()) return {};
    return{busStoplist};
  }
};

// Не меняя тела функции main, реализуйте функции и классы выше


int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
