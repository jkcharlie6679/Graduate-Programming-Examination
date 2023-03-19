/*
 * The Hotel with Infinite Rooms
 * Source: http://uva.onlinejudge.org/external/101/10170.html
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char** argv) {
  uint64_t S = 0, D = 0;
  while (cin >> S >> D) {
    uint64_t res = 0;
    if(cin.eof())
      break;
    for (int i = S; ; i++) {
      res += i;
      if (res >= D) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
