#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <sstream>
#include <map>
#include <cstdint>
#include <set>
#include <iomanip>


using namespace std;

class Date {
private:
  int year;
  int month;
  int day;
public:

  Date() {
    year = 0001;
    month = 01;
    day = 01;
  }

  Date (int y, int m, int d) {
    year = y;
    if(m > 12 || m < 1) {
      throw logic_error("Month value is invalid: " + to_string(m));
    }else month = m;
    if (d > 31 || d < 1) {
      throw logic_error ("Day value is invalid: " + to_string(d));
    }else day = d;
  }

  int GetYear() const{
    return year;
  }
  int GetMonth() const{
    return month;
  }
  int GetDay() const{
    return day;
  }
};

bool operator<(const Date& lhs, const Date& rhs){
  return
  vector<int> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
  vector<int> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<< (ostream& stream, const Date& d) {
  stream << setw(4) << setfill('0') << d.GetYear() <<'-' <<
  setw(2)<< setfill('0') << d.GetMonth()<< '-' <<
  setw(2)<< setfill('0') << d.GetDay();
  return stream;
}

istream& operator>> (istream& stream_in, Date& dt) {
  string out;

  stream_in >> out;
  stringstream stream(out);
  int y = 0, m = -1, d = -1;
  char s1, s2;
  stream >> y;
  stream >> s1;
  if (s1 != '-' ) {
    throw logic_error("Wrong date format: " + out );
  }
  stream >> m;
  if (m == -1) {
    throw logic_error("Wrong date format: " + out );
  }
  stream >> s2;
  if (s2 != '-' ) {
    throw logic_error("Wrong date format: " + out );
  }
  stream >> d;
  if (d == -1) {
    throw logic_error("Wrong date format: " + out );
  }
  if(!stream.eof()) throw logic_error("Wrong date format: " + out );
  dt = {y, m, d};
  return stream_in;

}

class Database {
private:
  map<Date, set<string>> db;
public:
  void AddEvent(const Date& date, const string& event) {
    db[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    if (db.count(date)) {
      if(db[date].count(event)) {
        db[date].erase(event);
        return true;
      }
    }
    return false;
  }

  int  DeleteDate(const Date& date) {
    int elems = 0;
    if (db.count(date)) {
      elems = db[date].size();
      db.erase(date);
    }
    return elems;
  }

   set <string> Find(const Date& date) const {
    if(db.count(date)) {
      return db.at(date);
    }
    return{};
  }

  void Print() const{
    for(auto [date, events]: db){
      for(string event : events) {
        cout<< date << ' ' << event<< '\n';
      }
    }
  }
};

void printEvents(const set<string>& st) {
  int cnt = 0;
  for(string elem: st){
    cout << elem << '\n';
  }
}

int main() {
  Database db;
  string command;
  try {
    while (getline(cin, command)) {
      stringstream ss(command);
      string cmd;
      ss >> cmd;


      if(cmd == "Add") {
        Date dd;
        string event;
        ss >> dd >> event;
        db.AddEvent(dd, event);
      }


      else if (cmd == "Del") {
        Date dd;
        string event;
        ss >> dd >> event;
        if(!event.length()) {
          int deleted = db.DeleteDate(dd);
          cout <<"Deleted " << deleted << " events" << '\n';
        }else if (event.length()) {
          if (db.DeleteEvent(dd, event))
            cout << "Deleted successfully" << '\n';
            else cout << "Event not found" << '\n';
        }
      }


      else if (cmd == "Find") {
        Date dd;
        ss >> dd;
        set <string> events;
        events = db.Find(dd);
        if (events.size()) {
          printEvents(events);
        }
      }


      else if (cmd == "Print") {
        db.Print();
      }


      else if (cmd == "") continue;

      else{
        throw logic_error("Unknown command: " + cmd);
      }
    }
  }catch (exception& e) {
    cout << e.what() << '\n';
  }

  return 0;
}
