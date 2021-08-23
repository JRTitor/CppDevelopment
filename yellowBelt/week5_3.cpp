#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure {
public:
  virtual string Name() = 0;
  virtual double Perimeter() = 0;
  virtual double Area() = 0;
};
class Triangle: public Figure {
private:
  int a, b, c;
public:
  Triangle(const int ina, const int& inb, const int& inc) :
    a(ina), b(inb), c(inc) {}
  string Name() override {
    return "TRIANGLE";
  }
  double Perimeter() override {
    return a + b + c;
  }
  double Area() override {
    int pn2 = (a + b + c)/2;
    return sqrt((pn2-a)*(pn2-b)*(pn2-c)*pn2);
  }
};
class Rect: public Figure {
  private:
    int width, height;
  public:
    Rect(const int& inw, const int& inh) :
      width(inw), height(inh) {}
    string Name() override {
      return "RECT";
    }
    double Perimeter()override {
      return (width + height) * 2;
    }
    double Area() override {
      return width * height;
    }
};

class Circle: public Figure {
private: int radius;
public:
  Circle(const int& r) : radius(r){}
  string Name() override {
    return "CIRCLE";
  }
  double Perimeter() override {
    return 3.14 * radius * 2;
  }
  double Area() override {
    return 3.14 * radius * radius;
  }
};

shared_ptr<Figure> CreateFigure(istream& input_stream) {
  string quer, s;
  input_stream >> quer;
  if(quer == "CIRCLE") {
    int radius;
    input_stream >> radius;
    return make_shared<Circle>(radius);
  }
  else if(quer == "RECT") {
    int width, height;
    input_stream >> width >> height;
    return make_shared<Rect> (width, height);
  }
  else if(quer == "TRIANGLE") {
    int a, b, c;
    input_stream >> a >> b >> c;
    return make_shared<Triangle> (a, b, c);
  }
  return 0;
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3) << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
