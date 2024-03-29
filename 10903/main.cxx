/*
 * Rock-Paper-Scissors Tournamen
 * Source: https://onlinejudge.org/external/109/10903.html
 */

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main () {
  bool space = false;
  int state[105][2];
  int n = 0, k = 0;
  int a = 0, b = 0;
  string m1 = "", m2 = "";
  while (scanf("%d", &n) != EOF && n != 0){
    if (space)
      cout << endl;
    space = true;
    scanf("%d", &k);
    memset(state, 0, sizeof(state));
    for (int i = 0; i < k*n*(n-1)/2; i++) {
      cin >> a >> m1 >> b >> m2;
      if (m1[0] != m2[0]) {
        if (m1[0] == 'r' && m2[0] == 's' || m1[0] == 's' && m2[0] == 'p' || m1[0] == 'p' && m2[0] == 'r' ) {
          state[a][1]++;
          state[b][0]++;
        } else {
          state[a][0]++;
          state[b][1]++;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      int total = state[i][0] + state[i][1];
      if (total == 0)
        cout << "-" << endl;
      else
      printf("%0.3f\n", (float)state[i][1] / (float)total);
    }
  }
  return 0;
}
