#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
  FunctionPart(const char& new_opertation, const double& new_value) {
    operation = new_opertation;
    value = new_value;
  }
  double Apply (const double& new_value) const {
    if (operation == '+') return new_value + value;
    else return new_value - value;
  }
  void Invert() {
    if (operation == '+') operation = '-';
    else operation = '+';
  }

private:
  char operation;
  double value;
};

class Function {
public:
  void AddPart(const char& oper, const double& value) {
    v.push_back({oper, value});
  }

  double Apply(double value) const {
    for (const FunctionPart& item: v) {
      value = item.Apply(value);
    }
    return value;
  }

  void Invert() {
    for(FunctionPart& item: v) {
      item.Invert();
    }
    reverse(begin(v), end(v));
  }
private:
  vector<FunctionPart> v;
};
