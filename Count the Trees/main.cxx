/*
 * # Count the Trees
 *
 * Time Limit: 3 sec
 *
 * ## Descript
 * Another common social inability is known as ACM (Abnormally Compulsive Meditation). This psychological disorder is somewhat common among programmers. It can be described as the temporary (although frequent) loss of the faculty of speech when the whole power of the brain is applied to something extremely interesting or challenging. Juan is a very gifted programmer, and has a severe case of ACM (he even participated in an ACM world championship a few months ago). Lately, his loved ones are worried about him, because he has found a new exciting problem to exercise his intellectual powers, and he has been speechless for several weeks now. The problem is the determination of the number of different labeled binary trees that can be built using exactly n different elements. For example, given one element A, just one binary tree can be formed (using A as the root of the tree). With two elements, A and B, four different binary trees can be created, as shown in the figure. If you are able to provide a solution for this problem, Juan will be able to talk again, and his friends and family will be forever grateful.
 *
 * ## Input
 * The input will consist of several input cases, one per line. Each input case will be specified by the number n ( 1 ≤ n ≤ 300 ) of different elements that must be used to form the trees. A number 0 will mark the end of input and is not to be processed.
 *
 * ## Output
 * For each input case print the number of binary trees that can be built using the n elements, followed by a newline character.
 *
 * ## Reference
 * Source: http://uva.onlinejudge.org/external/100/10007.html
 * Keyword: Catalan number
 *
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

