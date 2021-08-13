#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y){
  return x+y;
}
string Reverse(string s){
  string out;
  for(size_t i = s.length() - 1; i >0 ; --i) {
    out += s[i];
  }
  return out;
}
void Sort(vector<int>& nums){
  sort(nums.begin(), nums.end());
}
