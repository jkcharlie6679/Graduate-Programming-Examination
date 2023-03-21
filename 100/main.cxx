/*
 * The 3n + 1 problem
 * Source: https://onlinejudge.org/external/1/100.pdf
 */


#include <iostream>

using namespace std;

uint64_t MAX = 0;

void func (int input) {
  int iter = 1;
  while(input != 1) {
    if (input % 2 == 1)
      input = 3 * input + 1;
    else
      input /= 2;
    iter++;
  }
  if (MAX < iter)
    MAX = iter;
}

void swap (int &a, int &b) {
  int tmp = 0;
  tmp = a;
  a = b;
  b = tmp;
}

int main () {
  int a = 0, b = 0, tmp = 0;
  while (cin >> a >> b) {
    bool change = false;
    if (a > b) {
      swap(a, b);
      change = true;
    }
    MAX = 0;
    for (int i = a; i <= b; i++) {
      func(i);
    }
    if (change) {
      swap(a, b);
    }
    printf("%d %d %lld\n", a, b, MAX);
  }
  return 0;
}
