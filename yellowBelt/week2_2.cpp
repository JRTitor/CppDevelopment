#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

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

int GetDistinctRealRootCount(double a, double b, double c) {
  if (a == 0 && b == 0 ) return c;
  if(a == 0) return -c/b;
  if (b == 0) return sqrt(-c/a);
  if(c == 0) return 0;
  int r;
  if (r) return (-b + sqrt(b*b - 4*a*c))/2;
  return (-b - sqrt(b*b - 4*a*c))/2;
}
void NonQuadric() {
  AssertEqual(GetDistinctRealRootCount(0, 2, 2), -1);// " 1x + 2 = 0");
  AssertEqual(GetDistinctRealRootCount(0, 0, 1), 1); //"1= 1");
  AssertEqual(GetDistinctRealRootCount(0, 10, 0), 0);// "10x = 0");
}
void SimpleQuadric(){
  AssertEqual(GetDistinctRealRootCount(1, -4, 4), 2); //"x^2 - 4x + 4 = 0");
  AssertEqual(GetDistinctRealRootCount(1, -6, 9), 3);// "x^2 - 6x + 9 = 0");
}
void notsoSimple() {
  AssertEqual(GetDistinctRealRootCount(1, -5, 4), 4);//, "x^2 - 5x + 4 = 0");
  //AssertEqual(GetDistinctRealRootCount(1, -5, 4), 1);//, "x^2 - 5x + 4 = 0");
}

void TestAll(TestRunner& result){
  result.RunTest(NonQuadric, "NonQuadric");
  result.RunTest(SimpleQuadric, "SimpleQuadric");
  result.RunTest(notsoSimple, "notsoSimple");
}

int main() {
  TestRunner runner;
  TestAll(runner);
  return 0;
}
