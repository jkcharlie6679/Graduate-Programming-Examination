/*
 * Rank the Languages
 * Source: https://onlinejudge.org/external/103/10336.html
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

uint64_t max_ans = 0;

void color (char **table, char target, int h, int w, int j, int k) {
  table[j][k] = '0';
  for (int a = -1; a <= 1; a++) {
    for (int b = -1; b <= 1; b++) {
      if (j+a>=0 && k+b>=0 && j+a<h && k+b<w) {
        if (table[j+a][k+b] == target && (a == 0 || b == 0)) {
          color(table, target, h, w, j+a, k+b);
        }
      }
    }
  }
}

void compute (char **table, int h, int w, map<char, int> &ans) {
  for (int j = 0; j < h; j++) {
      for (int k = 0; k < w; k++) {
        if (table[j][k] != '0') {
          ans[table[j][k]]++;
          if (max_ans < ans[table[j][k]])
            max_ans = ans[table[j][k]];
          color(table, table[j][k], h, w, j, k);
        }
      }
    }
}

int main () {
  int num_case = 0;
  char input;
  char **table;
  cin >> num_case;
  for (int i = 0; i < num_case; i++) {
    int h = 0, w = 0;
    map<char, int> ans;
    scanf("%d %d", &h, &w);
    table = (char**) malloc(h*sizeof(char*));
    for (int i =0; i < h; i++) {
      table[i] = (char*) malloc(w*sizeof(char));
      memset(table[i], 0, w*sizeof(char));
    }
    for (int j = 0; j < h; j++) {
      for (int k = 0; k < w; k++) {
        cin >> input;
        table[j][k] = input;
      }
    }
    compute(table, h, w, ans);
    printf("World #%d\n", i+1);
    for (int j = max_ans; j > 0; j--) {
      map<char, int> tmp = ans;
      for (auto i : tmp) {
        if (j == i.second) {
          cout << i.first << ": " << i.second << endl;
          ans.erase(i.first);
        }
      }
    }
  }
  return 0;
}
