#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
  Person(const string& Name, const string& Occupation):
  name(Name), ouccpation(Occupation) {}

  string GetName() const{
    return name;
  }
  string GetOccup() const{
    return ouccpation;
  }
  virtual void Walk(const string& destination) const = 0;
private:
  const string name;
  const string ouccpation;
};


class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong):
    Person(name, "Student"),  FavouriteSong(favouriteSong) {}

    void Learn() const{
        cout << "Student: " << GetName() << " learns" << '\n';
    }

    void Walk(const string& destination) const override{
        cout << "Student: " << GetName() << " walks to: " << destination << '\n';
        SingSong();
    }

    void SingSong() const{
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << '\n';
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string&  name, const string&  subject) :
     Person(name, "Teacher"), Subject(subject){}

    void Teach() {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << '\n';
    }

    void Walk(const string&  destination) const override{
        cout << "Teacher: " << GetName() << " walks to: " << destination << '\n';
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string&  name) : Person(name, "Policeman"){}

    void Check(const Person& p) {
        cout << "Policeman: " << GetName() << " checks "<< p.GetOccup()<<
        ". "<< p.GetOccup()<<"'s name is: " << p.GetName() << '\n';
    }

    void Walk(const string&  destination) const override {
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }

private:
    string Name;
};


void VisitPlaces(const Person& p, const vector<string>& places) {
    for (auto pl : places) {
        p.Walk(pl);
    }
}



int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
