/*
 * Fermat vs. Pythagoras
 * Source: https://onlinejudge.org/external/1/106.pdf
 */
#include<iostream>
#define MAX 1000001

using namespace std;

int f[MAX], 
    num[MAX], 
    p[MAX], 
    ans[MAX] = {0, 1}; // init the number 1 for not use

int gcd(int a, int b) {
  return a % b ? gcd(b, a%b) : b;
}


int main() {
  fill(f, f + MAX, MAX);
  for (int m = 2; m < 1000; m++) {
    for (int n = (m & 1) + 1; n < m; n += 2) {
      if (gcd(m, n) != 1) 
        continue;
      int x = m*m - n*n, 
          y = 2*m*n,
          z = m*m + n*n;
      if (z >= MAX) 
        break;
      p[z]++;
      for(int k = MAX / z; k >= 1; k--) {
        int xx = x * k, yy = y * k, zz = z * k;
        f[xx] = min(f[xx], zz); // record the biggest number of set which is smallest set
        f[yy] = min(f[yy], zz);
        f[zz] = zz;
      }
    }
  }
  // cout << f[5] << endl;
  for (int i = 1; i <= MAX; i++) {
    p[i] += p[i - 1];
    num[f[i]]++;
  }
  for (int i = 2; i <= MAX; i++)
      ans[i] = ans[i - 1] + 1 - num[i];
  int N;
  while (scanf("%d", &N) == 1) 
    printf("%d %d\n", p[N], ans[N]);
  return 0;
}