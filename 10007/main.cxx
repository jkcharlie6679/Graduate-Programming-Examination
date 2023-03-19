/*
 * Count the Trees
 * Source: http://uva.onlinejudge.org/external/100/10007.html
 */

#include<iostream>
using namespace std;
const int MAX = 1e8;
uint64_t ans[uint64_t(1e6)+50];

/*
 * ANS = Catalan number * N!
 * - Catalan number for the how many shape of the tree
 *   C = 1/(n+1) * 2n!/(n!*n!)
 * - N! for the permutation
 */
int main(){
  int n;
  while(cin>>n && n){
    ans[0] = 1;
    int len = 0;
    // (N+2)*...*(2N)
    for(int i = n + 2; i <= 2 * n; i++){
      int temp = 0;
      for(int j = 0; j <= len; j++){
        ans[j] = ans[j] * i + temp;
        temp = ans[j] / MAX;  // upper
        ans[j] %= MAX;      // lower
      }
      if(temp>0)
        ans[++len]=temp;
    }
    // print the result
    printf("%lld",ans[len]);
    for(int i = len - 1; i >= 0; i--)
      printf("%08lld",ans[i]);
    cout<<endl;
  }
}

