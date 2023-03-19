/*
 * Reverse and Add
 * Source: https://onlinejudge.org/external/100/10018.html
 */

#include <iostream>
#include <string>

using namespace std;

bool is_pd (string &str, int s, int e) {
  while (s < e) {
    if (str[s] != str[e])
      return false;
    s++;
    e--;
  }
  return true;
}

string add_reserve (string &str) {
  uint64_t ori = stoull(str);
  uint64_t res = 0;
  for (int i = str.length(); i > 0; i--) {
    res = res * 10 + str[i-1] - '0';
  }
  return to_string(res+ori);
}

int main () {
  uint64_t n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string input = "";
    uint64_t ans = 0;
    cin >> input;
    while (!is_pd(input, 0, input.length() -1)){
      input = add_reserve(input);
      ans++;
    }
    printf("%lld %s\n", ans, input.c_str());
  }
  return 0;
}
