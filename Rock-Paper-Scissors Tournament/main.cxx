/*
 * # Rock-Paper-Scissors Tournamen
 * 
 * Rock-Paper-Scissors is game for two players, A and B, who each choose, independently of the other,
 * one of rock, paper, or scissors. A player chosing paper wins over a player chosing rock; a player chosing scissors wins over a player chosing paper; a player chosing rock wins over a player chosing scissors. A player chosing the same thing as the other player neither wins nor loses. 
 * 
 * A tournament has been organized in which each of n players plays k rock-scissors-paper games with each of the other players — k ∗ n ∗ (n − 1)/2 games in total. Your job is to compute the win average for each player, defined as w/(w + l) where w is the number of games won, and l is the number of games lost, by the player.
 * 
 * ## Input
 * 
 * Input consists of several test cases. The first line of input for each case contains 1 ≤ n ≤ 100 1 ≤ k ≤ 100 as defined above. For each game, a line follows containing p1, m1, p2, m2. 1 ≤ p1 ≤ n and 1 ≤ p2 ≤ n are distinct integers identifying two players; m1 and m2 are their respective moves (‘rock’, ‘scissors’, or ‘paper’). A line containing ‘0’ follows the last test case.
 * 
 * ## Output
 * 
 * Output one line each for player 1, player 2, and so on, through player n, giving the player’s win average rounded to three decimal places. If the win average is undefined, output ‘-’. Output an empty line between cases.
 * 
 * ## Reference
 * 
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
