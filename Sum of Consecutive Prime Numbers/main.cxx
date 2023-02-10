/*
 * # Sum of Consecutive Prime Numbers
 *
 * Time Limit: 3 sec
 * 
 * ## Description
 *
 * Some positive integers can be represented by a sum of one or more consecutive prime numbers. How many such representations does a given positive integer have? For example, the integer 53 has two representations 5 + 7 + 11 + 13 + 17 and 53 . The integer 41 has three representations 2 + 3 + 5 + 7 + 11 + 13 , 11 + 13 + 17 , and 41 . The integer 3 has only one representation, which is 3. The integer 20 has no such representations. Note that summands must be consecutive prime numbers, so neither 7 + 13 nor 3 + 5 + 5 + 7 is a valid representation for the integer 20. Your mission is to write a program that reports the number of representations for the given positive integer.
 *
 * ## Input
 * The input is a sequence of positive integers each in a separate line. The integers are between 2 and 10000, inclusive. The end of the input is indicated by a zero.
 *
 * ## Output
 * The output should be composed of lines each corresponding to an input line except the last zero. An output line includes the number of representations for the input integer as the sum of one or more consecutive prime numbers. No other characters should be inserted in the output.
 *
 * ## Reference
 *
 * Source: http://uva.onlinejudge.org/external/12/1210.html
 * Keyword:
 */

#include <iostream>
#include <vector>

using namespace std;


int checkPrimeNumber(int input){
  for(int i = 2; i <= input / 2; i++){
    if(input % i == 0)
      return 0;
  }
  return 1;
}

int main(){
  const int maxn = 10000;
  vector<int> prime;
  for(int i = 2; i <= maxn; i++){
    if(checkPrimeNumber(i)){
      prime.push_back(i);
    }
  }
  int getNumber = 0;
  while (cin >> getNumber){
    if(getNumber == 0)
      break;
    int ansCount = 0;
    for(int i = 0; (prime[i] <= getNumber) || (i < prime.size()); i++){
      int sum = 0;
      for(int j = i; sum < getNumber; j++){
        sum += prime[j];
        if(sum == getNumber){
          ansCount += 1;
          break;
        }
      }
    }
    cout << ansCount << endl;
  } 
  return 0;
}

