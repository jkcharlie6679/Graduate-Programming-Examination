/*
 * Power Crisis
 * Source: https://onlinejudge.org/external/1/151.html
 */

#include <iostream>

using namespace std;

int main () {
  int n = 0;
  while (cin >> n && n != 0) {
    for (int i = 1; i < n; i++) {
      int turnoff = 0;
      for (int j = 2; j < n; j++) {
        turnoff = (turnoff+i) % j;
      }
      if (turnoff == 11) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}

