/*
 * # Prime Frequency
 * 
 * Given a string containing only alpha-numerals (0-9, A-Z and a-z) you have to count the frequency (the number of times the character is present) of all the characters and report only those characters whose frequency is a prime number. A prime number is a number, which is divisible by exactly two different integers. Some examples of prime numbers are 2, 3, 5, 7, 11 etc.
 * 
 * ## Input
 * 
 * The first line of the input is an integer T (0 < T < 201) that indicates how many sets of inputs are there. Each of the next T lines contains a single set of input. The input of each test set is a string consisting alpha-numerals only. The length of this string is positive and less than 2001.
 * 
 * ## Output
 * 
 * For each set of input produce one line of output. This line contains the serial of output followed by the characters whose frequency in the input string is a prime number. These characters are to be sorted in lexicographically ascending order. Here “lexicographically ascending” means ascending in terms of the ASCII values. Look at the output for sample input for details. If none of the character frequency is a prime number, you should print ‘empty’ (without the quotes) instead.
 * 
 * ## Reference
 * 
 * Source: http://uva.onlinejudge.org/external/107/10789.html
 * 
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

