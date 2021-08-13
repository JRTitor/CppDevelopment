#include "responses.h"

using namespace std;

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
