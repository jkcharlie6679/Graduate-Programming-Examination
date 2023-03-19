/*
 * Oil Deposits
 * Source: http://uva.onlinejudge.org/external/5/572.html
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
