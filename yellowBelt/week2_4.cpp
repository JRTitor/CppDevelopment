#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

/*class Rational {
public:
  // Ð’Ñ‹ Ð¼Ð¾Ð¶ÐµÑ‚Ðµ Ð²ÑÑ‚Ð°Ð²Ð»ÑÑ‚ÑŒ ÑÑŽÐ´Ð° Ñ€Ð°Ð·Ð»Ð¸Ñ‡Ð½Ñ‹Ðµ Ñ€ÐµÐ°Ð»Ð¸Ð·Ð°Ñ†Ð¸Ð¸,
  // Ñ‡Ñ‚Ð¾Ð±Ñ‹ Ð¿Ñ€Ð¾Ð²ÐµÑ€Ð¸Ñ‚ÑŒ, Ñ‡Ñ‚Ð¾ Ð²Ð°ÑˆÐ¸ Ñ‚ÐµÑÑ‚Ñ‹ Ð¿Ñ€Ð¾Ð¿ÑƒÑÐºÐ°ÑŽÑ‚ ÐºÐ¾Ñ€Ñ€ÐµÐºÑ‚Ð½Ñ‹Ð¹ ÐºÐ¾Ð´
  // Ð¸ Ð»Ð¾Ð²ÑÑ‚ Ð½ÐµÐºÐ¾Ñ€Ñ€ÐµÐºÑ‚Ð½Ñ‹Ð¹

  Rational();
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};*/
class Rational {
public:
    Rational() {
      num = 0;
      denom = 1;
    }

    Rational(int numerator, int denominator) {
      if (numerator == 0) {
        num = 0;
        denom = 1;
      }
      else {
        if (denominator == 0){
          throw invalid_argument("Invalid argument");
        }
        int nod = nodd(numerator, denominator);
        if (numerator * denominator > 0) {
          num = abs(numerator/nod);
          denom = abs(denominator/nod);
        }else  {
          num = -1 * abs(numerator/nod);
          denom = abs(denominator/nod);
        }
      }
    }

    int Numerator() const {
      return num;
    }

    int Denominator() const {
      return denom;
    }

private:
  int num;
  int denom;
  int nodd(int a, int b) {
    a = abs(a);
    b = abs(b);
    return gcd(a, b);
  }
};

bool operator == (const Rational& lhs, const Rational& rhs) {
  return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}
bool operator != (const Rational& lhs, const Rational& rhs) {
  return !(lhs == rhs);
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
  return { lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator() };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
  return { lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return { lhs.Numerator() * rhs.Numerator() , lhs.Denominator() * rhs.Denominator()};
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
  if (rhs.Numerator() == 0) {
    throw domain_error("Division by zero");
  }

  int ndup = gcd(lhs.Numerator(), rhs.Numerator());
  int ndwn = gcd(lhs.Denominator(), rhs.Denominator());
  return{
    (lhs.Numerator()/ndup) * (rhs.Denominator()/ndwn),
    (lhs.Denominator()/ndwn) * (rhs.Numerator()/ ndup)
  };
}

ostream& operator<< (ostream& stream, const Rational& r) {
  stream << r.Numerator() << "/" <<r.Denominator();
  return stream;
}

istream& operator>> (istream& stream, Rational& r) {

  int a, b;
  char s;
  stream >> a;
  stream >> s;
  stream >> b;
  if (stream && s == '/')  r = {a, b};
  return stream;

}

bool operator < (const Rational& lhs, const Rational& rhs) {
  return (lhs-rhs).Numerator() < 0;
}

void ZeroStuff(){
  Rational a, b(1,4);
  {
    Rational res(1, 4);
    AssertEqual(a+b, res, "Void + numeber = number");
  }
  {
    Rational res;
    AssertEqual(a*b, res, "Void * numeber = 0");
    AssertEqual(a/b, res, "Void / numeber = 0");
  }
  {
    Rational c(1, 4);
    Rational res(1, 2);
    AssertEqual(c+b, res, "Sum test");
  }


}


int main() {
  TestRunner runner;
  runner.RunTest(ZeroStuff, "Rational #1");
  // Ð´Ð¾Ð±Ð°Ð²ÑŒÑ‚Ðµ ÑÑŽÐ´Ð° ÑÐ²Ð¾Ð¸ Ñ‚ÐµÑÑ‚Ñ‹
  return 0;
}
