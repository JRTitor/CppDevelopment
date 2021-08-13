#include "query.h"

using namespace std;

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
