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
          throw invalid_argument("ERROR: denominator equal zero");
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
    throw domain_error("ERROR: divisivion by zero");
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


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
