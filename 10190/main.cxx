/*
 * Divide, But Not Quite Conquer!
 * Source: https://onlinejudge.org/external/101/10190.html
 */

#include <iostream>
#include <string>

using namespace std;

int main () {
  uint64_t n = 0, m = 0;
  while (scanf("%lld %lld", &n, &m) != EOF) {
    string ans = "";
    if (m == 1 || n == 1 || m == 0 || n == 0) {
      n = 0;
    } else {
      ans += to_string(n) + " ";
      while (n != 1) {
        if (n % m == 0) {
          n = n/m;
          ans += to_string(n) + " ";
        } else {
          n = 0;
          break;
        }
      }
    }
    if (n == 1)
      cout << ans.substr(0, ans.length() - 1) << endl;
    else
      cout << "Boring!" << endl;
  }
  return 0;
}
