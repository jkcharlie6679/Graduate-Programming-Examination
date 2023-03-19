/*
 * Checkers
 * Source: https://onlinejudge.org/external/119/11957.html
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int T = 0;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int bsize = 0, ans = 0;
    cin >> bsize;
    vector<string> board(bsize, "");
    vector<vector<int>> dp(bsize, vector<int>(bsize + 2, 0));
    for (int j = bsize - 1; j >= 0; j--) {
      string temp;
      cin >> temp;
      board.at(j) = temp;
    }

    for (int j = 1; j < bsize; j++) {
      for (int k = 0, l = 1; k < bsize; k++, l++) {
        if (board[j][k] == 'W' || board[j][k] == 'B') 
          continue;
        if (board[j - 1][k - 1] == 'W' || board[j - 1][k + 1] == 'W') {
          dp[j][l] = 1;
        } else {
          if (j >= 2 && board[j - 1][k - 1] == 'B') {
            if (board[j - 2][k - 2] == 'W') {
              dp[j][l] = 1;
              continue;
            }
            dp[j][l] += dp[j - 2][l - 2];
          } else {
            dp[j][l] += dp[j - 1][l - 1];
          }
          if (j >= 2 && board[j - 1][k + 1] == 'B') {
            if (board[j - 2][k + 2] == 'W') {
              dp[j][l] = 1;
              continue;
            }
            dp[j][l] += dp[j - 2][l + 2];
          } else {
            dp[j][l] += dp[j - 1][l + 1];
          }
        }
        dp[j][l] %= 1000007;
        if (j == bsize - 1) {
          ans += dp[j][l];
        }
      }
    }
    cout << "Case " << i + 1 << ": " << ans % 1000007 << endl;
  }
  return 0;
}
