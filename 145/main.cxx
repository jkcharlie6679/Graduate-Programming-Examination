/*
 * Gondwanaland Telecom
 * https://onlinejudge.org/external/1/145.pdf
 */

#include <iostream>
#include <string>

using namespace std;

int charging[5][3] = {{ 10,  6,  2},
                      { 25, 15,  5},
                      { 53, 33, 13},
                      { 87, 47, 17},
                      {144, 80, 30}};

int time_cal (int start, int end) {
  if (end % 100 < start % 100) {
    end += 60;
    end -= 100;
  }
  return (end - start)/100*60 + (end - start)%100;
}

int main () {
  string step;
  string number;
  int s_h, s_m, e_h, e_m;
  while (cin >> step) {
    if (step == "#") {
      break;
    }
    cin >> number >> s_h >> s_m >> e_h >> e_m;
    int distance = step[0] - 'A';
    int ss = s_h*100 + s_m, ee = e_h*100+e_m, tmp = 0;
    int total = 0;
    int d_time = 0, e_time = 0, n_time = 0;
    int do_twice = 1;
    if (ee < ss) {
      do_twice = 2;
      tmp = ee;
      ee = 2400;
    }
    for (int i = 0; i < do_twice; i++) {
      while (ss != ee) {
        if (ss >= 800 && ss < 1800) {
          if (ee > 800 && ee <= 1800) {
            d_time += time_cal(ss, ee);
            total += time_cal(ss, ee) * charging[distance][0];
            ss = ee;
            break;
          } else {
            d_time += time_cal(ss, 1800);
            total += time_cal(ss, 1800) * charging[distance][0];
            ss = 1800;
          }
        } else if (ss >= 1800 && ss < 2200) {
          if (ee > 1800 && ee <= 2200) {
            e_time += time_cal(ss, ee);
            total += time_cal(ss, ee) * charging[distance][1];
            ss = ee;
            break;
          } else {
            e_time += time_cal(ss, 2200);
            total += time_cal(ss, 2200) * charging[distance][1];
            ss = 2200;
          }
        } else if (ss >= 2200 && ss < 2400) {
          if (ee > 2200 && ee <= 2400) {
            n_time += time_cal(ss, ee);
            total += time_cal(ss, ee) * charging[distance][2];
            ss = ee;
            break;
          } else {
            n_time = time_cal(ss, 2400);
            total += time_cal(ss, 2400) * charging[distance][2];
            ss = 0;
          }
        } else if (ss >= 0 && ss < 800) {
          if (ee > 0 && ee <= 800) {
            n_time += time_cal(ss, ee);
            total += time_cal(ss, ee) * charging[distance][2];
            ss = ee;
            break;
          } else {
            n_time += time_cal(ss, 800);
            total += time_cal(ss, 800) * charging[distance][2];
            ss = 800;
          }
        }
      }
      ss = 0;
      ee = tmp;
    }
    printf("  %s%6d%6d%6d  %s%5d.%02d\n", number.c_str(), d_time, e_time, n_time, step.c_str(), total/100, total%100);
  }
  return 0;
}
