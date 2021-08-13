#include "phone_number.h"
#include <sstream>
#include <exception>
#include <iostream>

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number){
   stringstream ss(international_number);
   char pp;
   ss >> pp;
   if (pp != '+') throw invalid_argument("Invalid phone number format");
   getline(ss, country_code_, '-');
   getline(ss, city_code_, '-');
   getline(ss, local_number_);
   if(country_code_.empty() || city_code_.empty() || local_number_.empty())
    throw invalid_argument("Invalid phone number format");
}

string PhoneNumber::GetCountryCode() const{
  return country_code_;
}
string PhoneNumber::GetCityCode() const{
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const{
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const{
  return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}
