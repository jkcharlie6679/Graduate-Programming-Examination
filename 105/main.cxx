/*
 * The Skyline Problem
 * Source: https://onlinejudge.org/external/1/105.pdf
 */

#include <iostream>
#define MAX 10005
using namespace std;

int main () {
  int first = -1, last = -1;
  int L = 0, R = 0, H = 0;
  int building [MAX*2] = {0};
  while (scanf("%d %d %d\n", &L, &H, &R) != EOF) {
    if (first == -1)
      first = L; 
    if (R > last)
      last = R;
    for (int i = L*2; i < 2*R; i+=2) {
      if (building[i+1] < H)
        building[i+1] = H;
    }
  }
  int height = building[2*first+1];
  printf("%d %d ", first, building[2*first+1]);
  for (int i = first*2; i <= 2*last; i+=2) {
    if (building[i+1] != height) {
      printf("%d ", i/2);
      printf("%d", building[i+1]);
      if (i !=2*last)
        printf(" ");
      else
        printf("\n");
      height = building[i+1];
    }
  }
  return 0;
}
