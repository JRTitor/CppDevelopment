#include <iostream>
#include <string>

using namespace std;

struct Specialization {
  string value;
  explicit Specialization(string new_value) {
    value = new_value;
  }
};

struct Course {
  string value;
  explicit Course(string new_value) {
    value = new_value;
  }
};

struct Week {
  string value;
  explicit Week(string new_value) {
    value = new_value;
  }
};


struct LectureTitle {
  LectureTitle(Specialization new_sp,  Course new_cr,  Week new_wk) {
    specialization = new_sp.value;
    course = new_cr.value;
    week = new_wk.value;
  }

  string specialization;
  string course;
  string week;
};
