#include <iostream>
#include <exception>
#include <numeric>

using namespace std;

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

int main(int argc, char const *argv[]) {
  Rational a, b;
  char oper;
  Rational result;

  try{
    cin >> a >> oper >> b;
    if (oper == '+') {
      result = a+b;
    }
    if (oper == '-') {
      result = a-b;
    }
    if (oper == '*') {
      result = a*b;
    }
    if (oper == '/') {
      result = a/b;
    }
    cout << result << '\n';
  }catch (invalid_argument& e) {
    cout << e.what();
  }catch ( domain_error& e){
    cout << e.what();
  }
  return 0;
}
