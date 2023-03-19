/*
 * Sum of Consecutive Prime Numbers
 * Source: http://uva.onlinejudge.org/external/12/1210.html
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

