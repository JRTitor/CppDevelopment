#pragma once

#include "responses.h"

using namespace std;

class BusManager {
private:
  map<string,vector<string>> busStoplist;
  map<string,vector<string>> stopBuslist;
public:
  void AddBus(const string& bus, const vector<string>& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const;

  StopsForBusResponse GetStopsForBus(const string& bus) const;

  AllBusesResponse GetAllBuses() const;
};
