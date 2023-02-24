/*
 * # Robot Instructions
 * Time Limit: 3 sec
 * 
 * ## Description
 * You have a robot standing on the origin of x axis. The robot will be given some instructions. Your task is to predict its position after executing all the instructions. 
 * 
 * - LEFT: move one unit left (decrease p by 1, where p is the position of the robot before moving)
 * - RIGHT: move one unit right (increase p by 1)
 * - SAME AS i: perform the same action as in the i-th instruction. It is guaranteed that i is a positive integer not greater than the number of instructions before this.
 * ## Input
 * The first line contains the number of test cases T (T≤100). Each test case begins with an integer n ( 1≤n≤100), the number of instructions. Each of the following n lines contains an instruction.
 * 
 * ## Output
 * For each test case, print the final position of the robot. Note that after processing each test case, the robot should be reset to the origin.
 * 
 * ## Reference
 * Source: http://uva.onlinejudge.org/external/125/12503.html
 * Author: Rujia Liu, Special Thanks: Feng Chen, Md
 * Keyword:
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
