/*
 * Prime Frequency
 * Source: http://uva.onlinejudge.org/external/107/10789.html
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> prime;

void build_prime() {
  prime.push_back(2);
  for (int i = 2; i < 2020; i++) {
    for (int j = 2; j < i; j++) {
      if (i % j == 0)
        break;
      if (j == i - 1)
        prime.push_back(i);
    }
  }
}

int main () {
  build_prime();
  string cases;
  getline(cin, cases);
  for (int i = 0; i < stoi(cases); i++) {
    string input = "";
    map<char, int> table;
    getline(cin, input);
    for (int j = 0; j < input.length(); j++) {
      table[input[j]] += 1;
    }
    cout << "Case " << i+1 << ": ";
    string ans = "";
    for (auto i : table) {
      if (find(prime.begin(), prime.end(), i.second) != prime.end()) {
        ans += i.first;
      }
    }
    if (ans.length())
      cout << ans << endl;
    else
      cout << "empty" << endl;
  }
  return 0;
}

