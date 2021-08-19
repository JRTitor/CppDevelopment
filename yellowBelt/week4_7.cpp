#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if(range_end - range_begin < 2) {
    return;
  }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    RandomIt it = begin(elements) + elements.size()/2 ;
    MergeSort(begin(elements), it);
    MergeSort(it, end(elements));

    merge(begin(elements), it, it, end(elements),range_begin);
}

template <typename RandomIt>
void MergeSortV2(RandomIt range_begin, RandomIt range_end){
  if(range_end - range_begin < 2) {
    return;
  }
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  RandomIt it1 = begin(elements) + elements.size()/3 ;
  RandomIt it2 =  begin(elements) + 2*elements.size()/3 ;
  MergeSortV2(begin(elements), it1);
  MergeSortV2(it1, it2);
  MergeSortV2(it2, end(elements));

  vector<typename RandomIt::value_type> tmp;
  merge(begin(elements), it1, it1, it2, back_inserter(tmp));
  merge(begin(tmp), end(tmp), it2, end(elements), range_begin);

}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;

  vector<int> v2 = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSortV2(begin(v2), end(v2));
  for (int x : v2) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
