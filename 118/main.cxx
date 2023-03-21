/*
 * Mutant Flatworld Explorers
 * Source: https://onlinejudge.org/external/1/118.pdf
 */

#include <iostream>

using namespace std;

int main () {
  int L = 0, H = 0; // x, y
  scanf("%d %d\n", &L, &H);
  int scent[51][51] = {0};
  int x = 0, y = 0, w = 0;
  char dir;
  while (scanf("%d %d %c\n", &x, &y, &dir) != EOF) {
    bool fall = false;
    if (dir == 'N')
      w = 0;
    else if (dir == 'E')
      w = 1;
    else if (dir == 'S')
      w = 2;
    else if (dir == 'W')
      w = 3;
    string inst = "";
    cin >> inst;
    for (int i = 0; i < inst.length(); i++) {
      if (inst[i] == 'R')
        w = (w+1)%4;
      else if (inst[i] == 'L')
        w = !w ? 3 : w-1;
      else
        if (w == 0) {
          y += 1;
        } else if (w == 1) {
          x += 1;
        } else if (w == 2) {
          y -= 1;
        } else if (w == 3) {
          x -= 1;
        }
      if ((x > L || y > H || x < 0 || y < 0)) {
        y = y > H ? H : y;
        x = x > L ? L : x;
        y = y < 0 ? 0 : y;
        x = x < 0 ? 0 : x;
        if (fall == false && scent[x][y] == 0) {
          scent[x][y] = 1;
          fall = true;
          break;
        }
      }
    }
    printf("%d %d ", x, y);
    if (w == 0) {
      printf("N");
    } else if (w == 1) {
      printf("E");
    } else if (w == 2) {
      printf("S");
    } else if (w == 3) {
      printf("W");
    }
    if (fall)
      cout << " LOST" << endl;
    else
      cout << endl;
  }
  return 0;
}
