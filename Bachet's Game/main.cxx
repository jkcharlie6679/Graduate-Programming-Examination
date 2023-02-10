 /*
  * # Bachet's Game
  *
  * Time Limit: 7 sec
  * 
  * ## Description
  * Bachet's game is probably known to all but probably not by this name. Initially there are n stones on the table. There are two players Stan and Ollie, who move alternately. Stan always starts. The legal moves consist in removing at least one but not more than k stones from the table. The winner is the one to take the last stone.
  * Here we consider a variation of this game. The number of stones that can be removed in a single move must be a member of a certain set of m numbers. Among the mnumbers there is always 1 and thus the game never stalls.
  * 
  * ## Input
  * The input consists of a number of lines. Each line describes one game by a sequence of positive numbers. The first number is n ≤ 1000000 the number of stones on the table; the second number is m ≤ 10 giving the number of numbers that follow; the last m numbers on the line specify how many stones can be removed from the table in a single move.
  * 
  * ## Output
  * For each line of input, output one line saying either Stan wins or Ollie wins assuming that both of them play perfectly.
  * 
  * ## Reference
  *
  * Source:	http://uva.onlinejudge.org/external/104/10404.html
  * Author:	Piotr Rudnicki
  * Keywords: Knapsack
  */

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char** argv){
  while (!cin.eof()){
    vector<int> ans(1000005);
    vector<int> numbers;
    int total = 0, m = 0; 
    // enter the total number and the number for remove
    cin >> total >> m;
    if(total > 1000000 || total < 1 || m > 10 || m < 1)
      exit(1);
    for(int i=0; i<m; i++){
      int tmp;
      cin >> tmp;
      numbers.push_back(tmp);
    }
    /*
     * Stan start it, so we need only focus on Stan.
     * If the last stone is removed form Ollie when Stan remove the number[j]. It means Stan can remove and he win.
     * Two things for check
     * - Enough stone can be remove. number[j] <= i
     * - Last stone is remove by Ollie. ans[i - number[j]]
     */
    for (int i = 1; i <= total; i++){
      for (int j = 0; j < m; j++){
        if (numbers[j] <= i && !ans[i - numbers[j]]) {
          ans[i] = 1;
          break;
        }
      }
    }
    // Print the answer
    if(ans[total])
      cout << "Stan wins" << endl;
    else
      cout << "Ollie wins" << endl;
  }
  return 0;
}
