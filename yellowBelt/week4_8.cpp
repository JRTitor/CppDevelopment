#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;

class Date {
public:
  Date(int y, int m, int d){
    year = y;
    month = m;
    day = d;
  }
  time_t AsTimestamp() const {
    tm t;
    t.tm_sec  = 0;
    t.tm_min  = 0;
    t.tm_hour = 0;
    t.tm_mday = day;
    t.tm_mon  = month - 1;
    t.tm_year = year - 1900;
    t.tm_isdst = 0;
    return mktime(&t);
  }

private:
  int year;
  int month;
  int day;

};

Date InputDate(const string& s){
  stringstream ss(s);
  int year, day, month;
  char skip1, skip2;
  ss >> year >> skip1 >> month >> skip2 >> day;
  return{year, month, day};
}

int ComputeDaysDiff(const Date& date_to, const Date& date_from) {
  const time_t timestamp_to = date_to.AsTimestamp();
  const time_t timestamp_from = date_from.AsTimestamp();
  static constexpr int SECONDS_IN_DAY = 60 * 60 * 24;
  return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}

static const Date START_DATE = InputDate("2000-01-01");
static const Date END_DATE = InputDate("2100-01-01");
static const size_t DAY_COUNT = ComputeDaysDiff(END_DATE, START_DATE);




int main() {
  cout.precision(25);
  size_t q;
  vector<double> money(DAY_COUNT, .0);
  cin >> q;
  for (size_t i = 0; i < q; ++i) {
    string action, date1, date2;
    cin >> action >>  date1 >> date2;
    Date from = InputDate(date1);
    Date to = InputDate(date2);
    auto start_indx = ComputeDaysDiff(from, START_DATE);
    auto finish_indx = ComputeDaysDiff(to, START_DATE);
    if (action == "ComputeIncome"){
      cout << accumulate(money.begin() + start_indx, money.begin() + finish_indx + 1, 0.) << '\n';
    }
    if (action == "Earn"){
      double value;
      cin >> value;
      value /= ComputeDaysDiff(to, from) + 1;
      for (int j = start_indx; j <= finish_indx; ++j) {
        money[j] += value;
      }
    }
  }
  return 0;
}
