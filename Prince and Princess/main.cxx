/*
 * 
 * # Prince and Princes
 * 
 * ## Reference
 * 
 * Source: https://onlinejudge.org/external/106/10635.html
 * 
 */

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

// const int inf = 62510;
const int maxn = 62510;

int s[maxn], num[maxn], d[maxn];

int main() {
  int t, tt = 0;
  scanf("%d", &t);
  while(t--){
    int n, p, q;
    scanf("%d %d %d", &n, &p, &q);
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= p+1; i++) {
      int x;
      scanf("%d", &x);
      num[x] = i;
    }
    n = 0;
    for (int i = 0; i <= q; i++) {
      int x;
      scanf("%d", &x);
      if (num[x]) 
        s[n++] = num[x];
    }
    fill(d, d+n, maxn);
    for (int i = 0; i < n; i++) {
      *lower_bound(d, d+n, s[i]) = s[i];
    }
    printf("Case %d: %d\n", ++tt, int(lower_bound(d, d + n, maxn) - d));
  }
  return 0;
}