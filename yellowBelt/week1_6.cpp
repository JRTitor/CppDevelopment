#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <utility>

using namespace std;

template <typename First, typename Second> pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);
template <typename key, typename value> map<key, value> operator * (const map <key, value>& m1, const map <key, value>& m2);
template<typename T> vector<T> operator * (const vector<T>& v1, const vector<T>& v2 );
template <typename T> T Sqr(T x);


template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
  First f = p1.first * p2.first;
  Second s = p1.second * p2.second;
  return make_pair(f, s);
}
template <typename key, typename value>
map<key, value> operator * (const map <key, value>& m1, const map <key, value>& m2) {
  map<key, value> res;
  for(auto [k, v] : m1){
    res[k] = v*v;
  }
  return res;
}
template<typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2 ){
  vector<T> res;
  for (size_t i = 0; i < v1.size(); i++) {
    res.push_back(v1[i] * v2[i]);
  }
  return res;
}

 template <typename T>
 T Sqr(T x) {
   return x * x;
 }

int main() {
  // Пример вызова функции
  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }

  map <pair<double, double>, pair<int, int>> aLot{{{1.1, 2.2}, {3, 4}}, {{5.5, 6.6}, {7, 8}} };
  cout << "map of pairs and pairs:" << '\n';
  for(const auto& x: Sqr(aLot)){
    cout<< x.first.first << ' ' << x.first.second << ' ' << x.second.first <<
    ' ' << x.second.second << '\n';
  }

  return 0;
}
