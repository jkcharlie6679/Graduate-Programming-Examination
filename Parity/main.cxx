/*
 * # Parity
 * 
 * We define the parity of an integer n as the sum of the bits in binary representation computed modulo two. As an example, the number 21 = 101012 has three 1s in its binary representation so it has parity 3(mod2), or 1.
 * 
 * In this problem you have to calculate the parity of an integer 1 ≤ I ≤ 2147483647.
 * 
 * ## Input
 * 
 * Each line of the input has an integer I and the end of the input is indicated by a line where I = 0 that
 * should not be processed.
 * 
 * ## Output
 * 
 * For each integer I in the inputt you should print a line ‘The parity of B is P (mod 2).’, where B is the binary representation of I.
 * 
 * ## Reference
 * 
 * source: http://uva.onlinejudge.org/external/109/10931.html
 * 
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

