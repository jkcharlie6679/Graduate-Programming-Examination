#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int n = 0, N = 0;
int num[2][50] = {0};
map <string, int> h;

bool check() {
  char str[100] = {0};
  for (int i = 0, ii = 0, jj = 0; i < N; i++) {
    str[i] = num[ii][jj++] + '0';
    if (jj == n) {
      jj = 0;
      ii = 1;
    }
  }
  if (h[str])
    return true;
  for (int i = 0, ii = 1, jj = 0, t = 1; i < N; i++) {
    str[i] = num[ii][jj] + '0';
    jj += t;
    if (jj == n) {
      jj = n-1;
      t = -1;
      ii = 0;
    }
  }
  if (h[str])
    return true;
  for (int i = 0, ii = 0, jj = n-1, t = -1; i < N; i++) {
    str[i] = num[ii][jj] + '0';
    jj += t;
    if (jj == -1) {
      jj = n-1;
      ii = 1;
    }
  }
  if (h[str])
    return true;
  for (int i = 0, ii = 1, jj = n-1, t = -1; i < N; i++) {
    str[i] = num[ii][jj] + '0';
    jj += t;
    if (jj == -1) {
      jj = 0;
      ii = 0;
      t = 1;
    }
  }
  if (h[str])
    return true;
  else
    h[str] = 1;
  return false;
}

int main () {
  while (scanf("%d", &n) && n != 0) {
    h.clear();
    memset(num, 0, sizeof(num));
    N = 2*n;
    int a, b, t;
    char step;
    bool win = false;
    for (int i = 0; i < N; i++) {
      scanf("%d %d %c\n", &a, &b, &step);
      if (win)
        continue;
      if (step == '+')
        t = 1;
      else
        t = -1;
      num[0][a-1] += t;
      num[1][b-1] += t;
      if (check()) {
        if (i%2 == 1)
          printf("Player 1 wins on move %d\n", i+1);
        else
          printf("Player 2 wins on move %d\n", i+1);
        win = true;
      }
    }
    if (!win)
      printf("Draw\n");
  }
  return 0;
}


