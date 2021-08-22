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

static const Date START_DATE = InputDate("1700-01-01");
static const Date END_DATE = InputDate("2100-01-01");
static const size_t DAY_COUNT = ComputeDaysDiff(END_DATE, START_DATE);




int main() {
  cout.precision(25);
  size_t q, e;
  vector<uint64_t> money(DAY_COUNT, 0);
  vector<uint64_t> partial_sums(DAY_COUNT, 0);
  cin >> e;
  for (size_t i = 0; i < e; ++i) {
    uint64_t earning;
    string date;
    cin >> date >> earning;
    Date earn_date = InputDate(date);
    auto indx = ComputeDaysDiff(earn_date, START_DATE);
    money[indx] = earning;
  }
  partial_sum(money.begin(), money.end(), partial_sums.begin());

  cin >> q;

  for (size_t i = 0; i < q; ++i) {
    string date_from, date_to;
    cin >> date_from >> date_to;
    Date from = InputDate(date_from);
    Date to = InputDate(date_to);
    auto start_indx = ComputeDaysDiff(from, START_DATE);
    auto finish_indx = ComputeDaysDiff(to, START_DATE);
    if (start_indx > 0) {
        cout << partial_sums[finish_indx] - partial_sums[start_indx - 1] << '\n';
    } else {
        cout << partial_sums[finish_indx] << '\n';
    }
  }

  return 0;
}
