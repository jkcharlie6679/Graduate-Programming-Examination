/*
 * Dollars
 * Source: http://uva.onlinejudge.org/external/1/147.html
 */

#include <iostream>

using namespace std;

const int numCoins = 11;
int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

const int SIZE = 30005;
long long possible[SIZE];

int main (int argc, char** argv) {
  possible[0] = 1; // for using the itself dollar
  for (int c = 0; c < numCoins; ++c) {
    for (int i = 0; i < SIZE - coins[c]; ++i) {
      possible[i + coins[c]] += possible[i];
    }
  }
  double num;
  while (scanf("%lf", &num), num > 0.0000001) {
    printf("%6.2f%17lld\n", num, possible[static_cast<int>(num * 100 + 0.5)]);
  }
}
