/*
 * Fill the Containers
 * Source:	 ttp://uva.onlinejudge.org/external/114/11413.html
 */

#include <iostream>
#include <vector>

using namespace std;

int main () {
  while (1) {
    int num_vessel = 0, num_container = 0;
    int left = 0, right = 0;
    vector<int> pool;
    cin >> num_vessel >> num_container;
    if (!num_container)
      break;
    for (int i = 0; i < num_vessel; i++) {
      int vessel = 0;
      cin >> vessel;
      pool.push_back(vessel);
      right += vessel;
      if (vessel > left)
        left = vessel;
    }
    while (left < right) {
      int mid = (right + left) / 2;
      int sum = 0;
      int amount = 0;
      for (int i = 0; i < num_vessel; i++) {
        sum += pool[i];
        if (sum > mid) {
          amount++;
          sum = pool[i];
        } else if (sum == mid) {
          amount++;
          sum = 0;
        }
      }
      if (sum)
        amount++;

      if (amount > num_container)
        left = mid + 1;
      else
        right = mid;
    }
    cout << left << endl;
  }


  return 0;
}

