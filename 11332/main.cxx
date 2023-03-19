/*
 * Summing Digits
 * Source: https://onlinejudge.org/external/113/11332.html
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  while (1) {
    string input = "";
    cin >> input;
    if (input == "0")
      break;
    while (input.length() != 1) {
      uint64_t ans = 0;
      for (int i = 0; i < input.length(); i++) {
        ans += input[i] - '0';
      }
      input = to_string(ans);
    }
    cout << input << endl;
  }
  return 0;
}
