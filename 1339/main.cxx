/*
 * Title: Ancient Cipher
 * Source: https://onlinejudge.org/external/13/1339.html
 */

#include <iostream>

using namespace std;

int main () {
  string s1 = "", s2 = "";
  while (cin >> s1 >> s2) {
    int a[26] = {0};
    int b[26] = {0};
    int m[110] = {0};
    int n[110] = {0};
    for (int i = 0; i < s1.length(); i++) {
      a[s1[i] - 'A']++;
      b[s2[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
      m[a[i]]++;
      n[b[i]]++;
    }
    bool ans = true;
    for (int i = 0; i < s1.length(); i++) {
      if (m[i] != n[i]) {
        ans = false;
        break;
      }
    }
    if (ans)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
  }
  return 0;
}
