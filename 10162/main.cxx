/*
 * Last Digit
 * Source: http://uva.onlinejudge.org/external/101/10162.html
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * 0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4
 * 4, 5, 9, 6, 2, 7, 3, 6, 2, 1, 1, 2, 8, 1, 7, 2, 8, 5, 9, 8
 * 8, 9, 3, 0, 6, 1, 7, 0, 6, 5, 5, 6, 2, 5, 1, 6, 2, 9, 3, 2
 * 2, 3, 7, 4, 0, 5, 1, 4, 0, 9, 9, 0, 6, 9, 5, 0, 6, 3, 7, 6
 * 6, 7, 1, 8, 4, 9, 5, 8, 4, 3, 3, 4, 0, 3, 9, 4, 0, 7, 1, 0
*/


int map[20] = {0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4};

int main (int argc, char** argv) {
  string num ;
  while (cin >> num) {
    int res = 0, value = 0;
    if(num.length() == 0 || num == "0")
      break;
    if (num.length() > 2) {
      value = stoi(num.substr(num.length()-2, 2));
    } else {
      value = stoi(num);
    }
    res = map[value%20] + 4 * (value/20);
    cout << res%10 << endl;
  }
  return 0;
}
