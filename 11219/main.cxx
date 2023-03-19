/*
 * How old are you?
 * Source: https://onlinejudge.org/external/112/11219.html
 */
#include <iostream>

using namespace std;

int main () {
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int d1 = 0, m1 = 0, y1 = 0;
    int d2 = 0, m2 = 0, y2 = 0;
    scanf("\n%d/%d/%d\n%d/%d/%d", &d1, &m1, &y1, &d2, &m2, &y2);
    printf("Case #%d: ", i+1);
    if (d1 == d2 && m1 == m2 && y1 == y2) {
      printf("0\n");
      continue;;
    }
    if (d1 < d2 && m1 == m2 && y1 == y2) {
      printf("Invalid birth date\n");
      continue;
    } else if (m1 < m2 && y1 == y2) {
      printf("Invalid birth date\n");
      continue;
    } else if (y1 < y2) {
      printf("Invalid birth date\n");
      continue;
    }

    int age = y1 - y2;
    if (m2 > m1 || (d2 > d1 && m1 == m2))
      age--;
    if (age > 130) {
      printf("Check birth date\n");
    } else {
      printf("%d\n", age);
    }
  }
  return 0;
}
