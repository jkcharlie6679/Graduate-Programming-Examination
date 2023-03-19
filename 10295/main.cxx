/*
 * Hay Points
 * Source: http://uva.onlinejudge.org/external/102/10295.html
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv){
  int words = 0, jobs = 0;
  unordered_map<string, int> dictionary;
  cin >> words >> jobs;
  for(int i = 0; i < words; i++){
    string word;
    int value;
    cin >> word >> value;
    dictionary[word] = value;
  }
  for(int i = 0; i < jobs; i++){
    string tmp = "";
    int total = 0;
    while(tmp != "."){
      cin >> tmp;
      total += dictionary[tmp];
    }
    cout << total << endl;
  }
  return 0;
}

