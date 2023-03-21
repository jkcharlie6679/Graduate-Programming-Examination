/*
 * Ugly NumbersU
 * Source: https://onlinejudge.org/external/1/136.pdf
 */

#include <iostream>

using namespace std;

int main () {
  int num = 1, ammount = 1;
  int pool[1501] = {0, 1, 0};
  while (pool[1500] == 0) {
    int x = 0, y = 0, z = 0;
    for (int i = 1; i <= num; i++) {
      if(pool[i] * 2 > pool[num] && x == 0) 
        x = pool[i];
      if(pool[i] * 3 > pool[num] && y == 0) 
        y = pool[i];
      if(pool[i] * 5 > pool[num] && z == 0) 
        z = pool[i];
      if (x != 0 && y != 0 && z != 0)
        break;
    }
    int tmp = min(x*2, y*3);
    pool[++num] = min(tmp, z*5);
  }
  
  printf("The 1500'th ugly number is %d.\n", pool[num]);
  return 0;
}
