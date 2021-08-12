#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool IsPalindrom(const string& str) {
  //this function is bad it must broke at TestNotPals: Test#5: gong
  int l = str.length() - 1;//remove -1
  int count = l/2;
  for (size_t i = 0; i < count; i++) {
    if(str[i] != str[l-i]) return false;// change str[l-i] to str[l-i-1]
  }// it works
  return true;
}
void TestPals() {
  AssertEqual(IsPalindrom("madam"), true, "Test#1: madam");
  AssertEqual(IsPalindrom("racecar"), true, "Test#2: racecar");
  AssertEqual(IsPalindrom("level"), true, "Test#3: level");
  AssertEqual(IsPalindrom("malayalam"), true, "Test#4: malayalam");
  AssertEqual(IsPalindrom(""), true, "Test#5: Void space");
  AssertEqual(IsPalindrom("stats"), true, "Test#6: stats");
  AssertEqual(IsPalindrom("I"), true, "Test#7: I");

}
void TestNotPals() {
  AssertEqual(IsPalindrom("madman"), false, "Test#1: madman");
  AssertEqual(IsPalindrom("runner"), false, "Test#2: runner");
  AssertEqual(IsPalindrom("long"), false, "Test#3: long");
  AssertEqual(IsPalindrom("long"), false, "Test#4: long");
  AssertEqual(IsPalindrom("gong"), false, "Test#5: gong");
  AssertEqual(IsPalindrom("stat"), false, "Test#6: stat");
}
void TestAll(TestRunner& runner) {
  runner.RunTest(TestPals, "TestPals");
  runner.RunTest(TestNotPals, "TestNotPals");
}

int main() {
  TestRunner runner;
  TestAll(runner);
  return 0;
}
