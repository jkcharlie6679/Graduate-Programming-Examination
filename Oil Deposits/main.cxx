/*
 * 
 * # Oil Deposits
 * 
 * Time Limit: 5 sec
 * 
 * ## Description
 * 
 * The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil.
 * 
 * A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid.
 * 
 * ## Input
 * 
 * The input file contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise 1 ≤ m ≤ 100 and 1 ≤ n ≤ 100.Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either `*', representing the absence of oil, or `@', representing an oil pocket.
 * 
 * ## Output
 * 
 * For each grid, output the number of distinct oil deposits. Two different pockets are part of the same oil deposit if they are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets.
 * 
 * ## Reference
 * 
 * Source: http://uva.onlinejudge.org/external/5/572.html
 * Author: Miguel A. Revilla, 1998-03-10
 * Keyword:
 * 
 */

#include <iostream>
#include <string>

#define MAXSIZE 100

using namespace std;

char map[MAXSIZE+1][MAXSIZE+1];
int M, N;

void color (int m, int n) {
  map[m][n] = '*';
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (m+i>=0 && m+i<M && n+j>=0 && n+j<N) {
        if(map[m+i][n+j]=='@') {
          color(m+i, n+j);
        }
      }
    }
  }
}

int compute (int m,int n) {
  int result = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == '@') {
        result++;
        color(i, j);
      }
    }
  }
  return result;
}


int main (int argc, char** argv) {
  int m = 0, n = 0;
  while (1) {
    string tmp;
    getline(cin, tmp);
    m = stoi(tmp.substr(0, tmp.find(" ")+1));
    n = stoi(tmp.substr(tmp.find(" ")+1, tmp.length() - tmp.find(" ")));
    if(m==0 && n==0)
      break;
    for (int i = 0; i < m; i++) {
      getline(cin, tmp);
      for (int j = 0; j < n; j++) {
        map[i][j] = tmp[j];
      }
    }

    M = m;
    N = n;
    cout << compute(m, n) << endl;
  }
}