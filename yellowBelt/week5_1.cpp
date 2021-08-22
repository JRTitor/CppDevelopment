#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    // ваш код
    Animal(const string& t) : Name(t) {
    }

    const string Name;
};


class Dog : public Animal{
public:
    // ваш код
    Dog(const string& name) : Animal(name){

    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
  Dog cat = Dog("Ed");
  cat.Bark();
  return 0;
}
