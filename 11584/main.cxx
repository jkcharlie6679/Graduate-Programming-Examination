/*
 * Partitioning by Palindromes
 * Source: https://onlinejudge.org/external/115/11584.html
 */

#include <iostream>
#include <vector>

using namespace std;

bool is_pd(string &str, int s, int e) {
  while (s < e) {
    if (str[s] != str[e])
     return false;
    s++;
    e--;
  }
  return true;
}

int main () {
  int n = 0;
  cin >> n;
  for (int k = 0; k < n; k++) {
    string input = "";
    cin >> input;
    vector<int> ans(input.length()+1, 0);
    ans [1] = 1;
    for (int i = 2; i <= input.length(); i++) {
      ans[i] = ans[i-1] + 1;
      for (int j = 0; j < i; j++) {
        if (is_pd(input, j, i-1))
          ans[i] = min(ans[j]+1, ans[i]);
      }
    }
    cout << ans[input.length()] << endl;
  }
  return 0;
}
