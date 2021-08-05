#include <iostream>
#include <map>
#include <utility>
#include <exception>

using namespace std;

template<typename key, typename value>
value& GetRefStrict(map <key, value>& m, key Key){
  if(!m.count(Key)) throw runtime_error("The key is not found");
  return m.at(Key);
}

int main() {
  try{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
  }catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
