/*
 * Robot Instructions
 * Source: http://uva.onlinejudge.org/external/125/12503.html
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (int argc, char** argv) {
  string cases = "";
  getline(cin, cases);
  for (int i = 0; i < stoull(cases); i++) {
    vector<int> step;
    string instr_num = "";
    int64_t res = 0;
    getline(cin, instr_num);
    for (int j = 0; j < stoull(instr_num); j++){
      string instru = "";
      getline(cin, instru);
      if (instru[0] == 'R') {
        res += 1;
        step.push_back(1);
      } else if (instru[0] == 'L') {
        res -= 1;
        step.push_back(-1);
      } else {
        int same = stoull(instru.substr(8, instru.length() - 8));
        step.push_back(step[same-1]);
        res += step[same-1];
      }
    }
    cout << res << endl;
  }
  return 0;
}
