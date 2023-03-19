/*
 * DNA Sorting
 * Source: https://onlinejudge.org/external/6/612.html
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {
  int n = 0;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    int line = 0, length = 0;
    vector<string> pool;
    vector<int> ans;
    scanf("\n%d %d\n", &length, &line);
    for (int j = 0; j < line; j++) {
      string input = "";
      getline(cin, input);
      pool.push_back(input);
      uint64_t weight = 0;
      for (int k = 0; k < length; k++) {
        for (int q = k; q < length; q++) {
          if (input[k] > input[q]) {
            weight++;
          }
        }
      }
      ans.push_back(weight);
    }

    for (int k = 0; k < line; k++) {
      uint64_t min = 10e9;
      int idx = 0;
      for (int j = 0; j < line; j++) {
        if (ans[j] < min && ans[j] >= 0) {
          min = ans[j];
          idx = j;
        }
      }
      printf("%s\n", pool[idx].c_str());
      ans[idx] = -1;
    }
    if (i != n-1)
      cout << endl;
  }
  return 0;
}
