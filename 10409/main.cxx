/*
 * Die Game
 * Source: http://uva.onlinejudge.org/external/104/10409.html
 */

#include <iostream>
#include <vector>

using namespace std;

void north (vector<int> &die) {
  int new_top = abs(7 - die[1]);
  die[1] = die[0];
  die[0] = new_top;
}

void south (vector<int> &die) {
  int new_north = abs(7 - die[0]);
  die[0] = die[1];
  die[1] = new_north;
}

void west (vector<int> &die) {
  int new_top = abs(7 - die[2]);
  die[2] = die[0];
  die[0] = new_top;
}

void east (vector<int> &die) {
  int new_west = abs(7 - die[0]);
  die[0] = die[2];
  die[2] = new_west;
}

int main (int argc, char** argv) {
  while (1) {
    vector<int> die = {1, 2, 3}; // top, north, west
    int step = 0;
    string direction;
    cin >> step;
    if (!step)
      break;
    for (int i = 0; i < step; i++) {
      cin >> direction;
      if (direction == "north") {
        north(die);
      } else if (direction == "south") {
        south(die);
      } else if (direction == "west") {
        west(die);
      } else if (direction == "east") {
        east(die);
      }
    }
    cout << die[0] << endl;
  }
  return 0;
}

