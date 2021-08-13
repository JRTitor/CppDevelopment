#pragma once

#include "responses.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct BusesForStopResponse {
// Наполните полями эту структуру
  string stop;
  vector<string> buses;
};
ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  string bus;
  vector<string> stops;
  map<string, BusesForStopResponse> busesForStop;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
// Наполните полями эту структуру
  map<string, vector<string>> bsList;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
