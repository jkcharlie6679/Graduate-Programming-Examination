/*
 * Joseph's Cousin
 * Source: https://onlinejudge.org/external/100/10015.html
 */

#include <iostream>
#include <vector>

#define MAX_NUM 3510

using namespace std;

vector <int> prime;

void build_prime () {
  for (int i = 2; ; i++) {
    for (int j = 2; j <= i; j++ ) {
      if (j == i)
        prime.push_back(i);
      else if (i%j == 0)
        break;
    }
    if (prime.size() == MAX_NUM)
      break;
  }
  return;
}

int main () {
  build_prime();
  while (1) {
    int number = 0;
    int table[MAX_NUM] = {0};
    cin >> number;
    if (number == 0)
      break;
    int previous = 1;
    for (int i = number; i > 1; i--) {
      int victim = prime[number-i] % i;
      if (victim == 0)
        victim = prime[number-i];
      while (1) {
        if (table[previous] == 0) {
          if (victim == 1) {
            table[previous++] = 1;
            if (previous > number)
              previous = 1;
            break;
          } 
          victim--;
        }
        previous++;
        if (previous > number)
          previous = 1;
      }
    }
    for (int i = 1; ; i++) {
      if (table[i] == 0) {
        cout << i << endl;
        break;
      }
    }

    // int ans = 0;
    // for (int i = 2; i <= number; i++) {
    //   ans = (ans + prime[number-i]) % i;
    // }
    // cout << ans+1 << endl;


    // https://blog.csdn.net/mobius_strip/article/details/79696605
    // https://blog.csdn.net/tingyun_say/article/details/52343897
  }
  return 0;
}

