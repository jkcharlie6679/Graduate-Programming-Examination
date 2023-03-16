/*
 * # Joseph's Cousin
 * 
 * Time Limit: 60 sec
 * 
 * ## Description
 * 
 * The Joseph’s problem is notoriously known. For those who are not familiar with the problem, among n people numbered 1,2…n, standing in circle every mth is going to be executed and only the life of the last remaining person will be saved. Joseph was smart enough to choose the position of the last remaining person, thus saving his life to give the message about the incident. Although many good programmers have been saved since Joseph spread out this information, Joseph’s Cousin introduced a new variant of the malignant game. This insane character is known for its barbarian ideas and wishes to clean up the world from silly programmers. We had to infiltrate some the agents of the ACM in order to know the process in this new mortal game. In order to save yourself from this evil practice, you must develop a tool capable of predicting which person will be saved.
 * 
 * ## The Destructive Process
 * 
 * The persons are eliminated in a very peculiar order; m is a dynamical variable, which each time takes a different value corresponding to the prime numbers’ succession (2,3,5,7…). So in order to kill the ith person, Joseph’s cousin counts up to the ith prime.
 * 
 * ## Input
 * 
 * It consists of separate lines containing n [1..3501], and finishes with a 0.
 * 
 * ## Output
 * 
 * The output will consist in separate lines containing the position of the person which life will be saved.
 * 
 * ## Reference
 * 
 * Keyword: Joseph's Cousin
 * Source: https://onlinejudge.org/external/100/p10015.pdf
 * 
 */

#include <iostream>
#include <vector>

#define MAX_NUM 3510

using namespace std;

vector <int> prime;

void build_prime () {
  for (int i = 2; ; i++) {
    for (int j = 2; j <= i; j++ ) {
      if (j == i)
        prime.push_back(i);
      else if (i%j == 0)
        break;
    }
    if (prime.size() == MAX_NUM)
      break;
  }
  return;
}

int main () {
  build_prime();
  while (1) {
    int number = 0;
    int table[MAX_NUM] = {0};
    cin >> number;
    if (number == 0)
      break;
    int previous = 1;
    for (int i = number; i > 1; i--) {
      int victim = prime[number-i] % i;
      if (victim == 0)
        victim = prime[number-i];
      while (1) {
        if (table[previous] == 0) {
          if (victim == 1) {
            table[previous++] = 1;
            if (previous > number)
              previous = 1;
            break;
          } 
          victim--;
        }
        previous++;
        if (previous > number)
          previous = 1;
      }
    }
    for (int i = 1; ; i++) {
      if (table[i] == 0) {
        cout << i << endl;
        break;
      }
    }

    // int ans = 0;
    // for (int i = 2; i <= number; i++) {
    //   ans = (ans + prime[number-i]) % i;
    // }
    // cout << ans+1 << endl;


    // https://blog.csdn.net/mobius_strip/article/details/79696605
    // https://blog.csdn.net/tingyun_say/article/details/52343897
  }
  return 0;
}

