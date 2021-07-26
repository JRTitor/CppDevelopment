
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    int m = 0;
    vector<int> dm = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> v(31, vector<string>());
    int q;
    string oper;
    cin >> q;

    for (int i = 0; i < q; i++) {

        cin >> oper;
        if (oper == "ADD") {
            string s;
            int i;
            cin >> i;
            cin >> s;
            v[i-1].push_back(s);
          }
          if (oper == "DUMP") {
            int i;
            cin >> i;
            cout << v[i-1].size();
            for (string task: v[i-1])
                cout << " " << task;
            cout << '\n';
          }
          if (oper == "NEXT") {
            m = (m+ 1)%12;
            if (m != 0) {
                if (dm[m] == 28) {
                    v[27].insert(end(v[27]), begin(v[28]), end(v[28]));
                    v[27].insert(end(v[27]), begin(v[29]), end(v[29]));
                    v[27].insert(end(v[27]), begin(v[30]), end(v[30]));
                    v[29].clear();
                    v[28].clear();
                    v[30].clear();
                  }
                  else if (dm[m] == 30) {
                    v[29].insert(end(v[29]), begin(v[30]), end(v[30]));
                    v[30].clear();
                }
            }
        }
    }
  return 0;
}
