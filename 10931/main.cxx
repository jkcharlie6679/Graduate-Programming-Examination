/*
 * Parity
 * source: http://uva.onlinejudge.org/external/109/10931.html
 */

#include <iostream>
#include <string>

using namespace std;


int main () {
  uint64_t input = 0;
  while (1) {
    string ans = "";
    cin >> input;
    int parity = 0;
    if (!input)
      break;
    while (input > 1) {
      ans = to_string(input % 2) + ans;
      parity = (parity + input % 2);
      input = input / 2;
    }
    ans = to_string(input) + ans;
    parity += input;
    cout << "The parity of " << ans << " is " << parity << " (mod 2)." << endl;
  }
  return 0;
}

