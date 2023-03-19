/*
 * Maya Calendar
 * Source: https://onlinejudge.org/external/3/300.html
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> haab = {
  {"pop", 0}, {"no", 1}, {"zip", 2}, {"zotz", 3},
  {"tzec", 4}, {"xul", 5}, {"yoxkin", 6}, {"mol", 7},
  {"chen", 8}, {"yax", 9}, {"zac", 10}, {"ceh", 11},
  {"mac", 12}, {"kankin", 13}, {"muan", 14}, {"pax", 15},
  {"koyab", 16}, {"cumhu", 17}, {"uayet", 18}
};

map<uint64_t, string> tzolkin = {
  {1, "imix"}, {2, "ik"}, {3, "akbal"}, {4, "kan"},
  {5, "chicchan"}, {6, "cimi"}, {7, "manik"}, {8, "lamat"},
  {9, "muluk"}, {10, "ok"}, {11, "chuen"}, {12, "eb"},
  {13, "ben"}, {14, "ix"}, {15, "mem"}, {16, "cib"},
  {17, "caban"}, {18, "eznab"}, {19, "canac"}, {20, "ahau"},
};


int main () {
  int num_case = 0;
  scanf("%d", &num_case);
  cout << num_case << endl;
  for (int i = 0; i < num_case; i++) {
    string nday = "", nmonth = "", nyear = "";
    uint64_t total;
    cin >> nday >> nmonth >> nyear;
    total = stoi(nyear) * 365 + haab[nmonth] * 20 + stoi(nday.substr(0, nday.length()-1)) + 1;
    uint64_t onum = (total%13)==0 ? 13 : total%13;
    uint64_t oname = (total%20)==0 ? 20 : total%20;
    printf("%lld %s %lld\n", onum, tzolkin[oname].c_str(), (total-1)/260);
  }
  return 0;
}

