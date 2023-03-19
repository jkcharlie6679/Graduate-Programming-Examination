/*
 * Count on Cantor
 * Source: https://onlinejudge.org/external/2/264.html
 */

#include <iostream>

using namespace std;

int main () {
  int n = 0;
  while (scanf("%d", &n) != EOF) {
    int i, sum = 0, start = 0;
    for (i =0; sum < n; i++){
      sum += i;
    }
    if (sum > n) {
      sum = sum - i + 1; // upper
      int leave = n - sum; // leave
      if ((i-1) % 2 == 0) {
        printf("TERM %d IS %d/%d\n", n, leave, i - leave);
      } else {
        printf("TERM %d IS %d/%d\n", n, i - leave, leave);
      }
    } else {
      i--;
      if (i % 2 == 0){
        printf("TERM %d IS %d/1\n", n, i);
      } else {
        printf("TERM %d IS 1/%d\n", n, i);
      }
      
    }
  }
  return 0;
}
