/*
 * Bachet's Game
 * Source:	http://uva.onlinejudge.org/external/104/10404.html
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
