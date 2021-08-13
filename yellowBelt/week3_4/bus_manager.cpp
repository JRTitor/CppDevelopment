#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
  busStoplist[bus] = stops;
  for(const string& stop: stops) {
    stopBuslist[stop].push_back(bus);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {

  if(stopBuslist.count(stop) > 0) {
    return {stop, stopBuslist.at(stop)};
  }
  else return{};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
  vector<string> stops;
  if(busStoplist.count(bus) > 0) {
    stops = busStoplist.at(bus);
  }
  map<string, BusesForStopResponse> busesFstop;
  for(const string& stop: stops) {
    busesFstop[stop] = GetBusesForStop(stop);
  }
  return {bus, stops, busesFstop};
}

AllBusesResponse BusManager::GetAllBuses() const {
  if (busStoplist.empty()) return {};
  return {busStoplist};
}
