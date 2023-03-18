/*
 * # Partitioning by Palindromes
 * 
 * We say a sequence of characters is a palindrome if it is the same written forwards and backwards. For example, ‘racecar’ is a palindrome, but ‘fastcar’ is not.
 * 
 * A partition of a sequence of characters is a list of one or more disjoint non-empty groups of consecutive characters whose concatenation yields the initial sequence. For example, (‘race’, ‘car’) is a partition of ‘racecar’ into two groups.
 * 
 * Given a sequence of characters, we can always create a partition of these characters such that each group in the partition is a palindrome! Given this observation it is natural to ask: what is the minimum number of groups needed for a given string such that every group is a palindrome?
 * 
 * For example:
 *   - ‘racecar’ is already a palindrome, therefore it can be partitioned into one group.
 *   - ‘fastcar’ does not contain any non-trivial palindromes, so it must be partitioned as (‘f’, ‘a’, ‘s’, ‘t’, ‘c’, ‘a’, ‘r’).
 *   - ‘aaadbccb’ can be partitioned as (‘aaa’, ‘d’, ‘bccb’).
 * 
 * ## Input
 * 
 * Input begins with the number n of test cases. Each test case consists of a single line of between 1 and 1000 lowercase letters, with no whitespace within.
 * 
 * ## Output
 * 
 * For each test case, output a line containing the minimum number of groups required to partition the input into groups of palindromes.
 * 
 * ## Reference
 * 
 * Source: https://onlinejudge.org/external/115/11584.html
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

bool is_pd(string &str, int s, int e) {
  while (s < e) {
    if (str[s] != str[e])
     return false;
    s++;
    e--;
  }
  return true;
}

int main () {
  int n = 0;
  cin >> n;
  for (int k = 0; k < n; k++) {
    string input = "";
    cin >> input;
    vector<int> ans(input.length()+1, 0);
    ans [1] = 1;
    for (int i = 2; i <= input.length(); i++) {
      ans[i] = ans[i-1] + 1;
      for (int j = 0; j < i; j++) {
        if (is_pd(input, j, i-1))
          ans[i] = min(ans[j]+1, ans[i]);
      }
    }
    cout << ans[input.length()] << endl;
  }
  return 0;
}
