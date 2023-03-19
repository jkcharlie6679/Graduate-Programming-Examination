/*
 * Uncompress
 * Source: http://uva.onlinejudge.org/external/2/245.html
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void find_number (vector<string> &list, int number) {
  string tmp = list[list.size() - number];
  cout << tmp;
  list.erase(list.begin() + list.size() - number);
  list.push_back(tmp);
}

int main (int argc, char** argv) {
  vector<string> list;
  string line = "";
  while (1) {
    getline(cin, line);
    int index = 0, length = 0, num_length = 0;
    for (int i = 0; i < line.length(); i++) {
      if (line[0] == '0') {
        return 0;
      } else if((line[i] >= '0'  && line[i] <= '9')) {
        num_length++;
        if (i == line.length()-1) {
          find_number(list, stoull(line.substr(index, num_length)));
          num_length = 0;
        }
      } else if((line[i] >= 'A'  && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
        length++;
        if (i == line.length()-1) {
          cout << line.substr(index, length);
          list.push_back(line.substr(index, length));
          length = 0;
        }
      } else { 
        if (length != 0) {
          cout << line.substr(index, length);
          list.push_back(line.substr(index, length));
          length = 0;
        }
        if (num_length != 0) {
          find_number(list, stoull(line.substr(index, num_length)));
          num_length = 0;
        }
        index = i + 1;
        cout << line[i];
      }
    }
    cout << endl;
  }
  return 0;
}
