/*
 * # Bangla Numbers
 * Time Limit: 3 sec
 * ## Description
 * Bangla numbers normally use 'kuti' (10000000), 'lakh' (100000), 'hajar' (1000), 'shata' (100) while expanding and converting to text. You are going to write a program to convert a given number to text with them.
 * 
 * ## Input
 * The input file may contain several test cases. Each case will contain a non-negative number <= 999999999999999.
 * 
 * ## Output
 * For each case of input, you have to output a line starting with the case number with four digits adjustment followed by the converted text.
 * 
 * ## Reference
 * Source: https://onlinejudge.org/external/101/p10101.pdf
 * Keyword:
 *
*/

#include <iostream>
#include <iomanip>

using namespace std;

void split(long long n) {
  if (n >= 10000000) {
    split(n / 10000000);
    cout << " kuti";
    n %= 10000000;
  }
  if (n >= 100000) {
    split(n / 100000);
    cout << " lakh";
    n %= 100000;
  }
  if (n >= 1000) {
    split(n / 1000);
    cout << " hajar";
    n %= 1000;
  }
  if (n >= 100) {
    split(n / 100);
    cout << " shata";
    n %= 100;
  }
  if (n)
    cout << " " << n;
}

int main (int argc, char** argv) {
  long unsigned int n;
  int case_num = 1;
  while (cin >> n) {
    cout << setw(4) << case_num++ << ".";
    if (n) {
      split(n);
    } else {
      cout << " 0";
    }
    cout << endl;
  }
  return 0;
}
