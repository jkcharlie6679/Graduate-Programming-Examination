/*
 * # Rank the Languages
 * 
 * You might have noticed that English and Spanish are spoken in many areas all over the world. Now it would be nice to rank all languages according to the number of states where they are spoken. You’re given a map which shows the states and the languages where they are spoken. Look at the following map:
 * 
 * ttuuttdd
 * ttuuttdd
 * uuttuudd
 * uuttuudd
 * 
 * The map is read like this: Every letter stands for a language and states are defined as connected areas with the same letter. Two letters are “connected” if one is at left, at right, above or below the other one. So in the above map, there are three states where the language “t” is spoken, three where “u” is spoken and one state where people speak “d”. Your job is to determine the number of states for each language and print the results in a certain order.
 * 
 * ## Input
 * 
 * The first line contains the number of test cases N. Each test case consists of a line with two numbers H and W, which are the height and the width of the map. Then follow H lines with a string of W letters. Those letters will only be lowercase letters from ‘a’ to ‘z’.
 * 
 * ## Output
 * 
 * For each test case print ‘World #n’, where n is the number of the test case. After that print a line for each language that appears in the test case, which contains the language, a colon, a space and the number of states, where that language is spoken. These lines have to be ordered decreasingly by the number of states. If two languages are spoken in the same number of states, they have to appear alphabetically, which means language ‘i’ comes before language ‘q’, for example.
 * 
 * ## Reference
 * 
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
