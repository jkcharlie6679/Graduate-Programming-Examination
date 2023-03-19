/*
 * # Prefix expression evaluation
 * 
 * Time Limit: 30 sec
 * 
 * ## Description
 * 
 * Evaluate a given prefix arithmetic expression that consists of postive integer constants and binary operators +, -, *, /, and %. The meanings of the operators are standard. In particular, / and % are integer division for quotient and remainder, respectively. In case the expression is an illegal prefix expression, report it as "illegal".
 * 
 * You may assume that the expression contains only digits, spaces, and the five operators mentioned above.
 * 
 * ## Input
 * 
 * The input consists of multiple datasets, followed by a line which contains only a single ‘.’ (period). Each dataset represents a test data. Each dataset contains a prefix expression. The size of each line of an expression will be at most 1024. Each symbol or number is separated by at least one space.
 * 
 * ## Output
 * 
 * For each case, the output should indicate the calculation result of the input prefix expression. If the input expression is illegal, the output is the string “illegal”.
 * 
 * ## Hint
 * 
 * - * + 23 % 45 10 6 / 77 12
 * 
 * is the prefix expression of the following statement
 * 
 * {[23+(45%10)]*6}-(77/12)
 * 
 * ## Reference
 * 
 * Keyword:
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

int main (int argc, char** argv) {
  while (1) {
    string tmp = "";
    bool illegal = false;
    getline(cin, tmp);
    if (tmp == ".")
      return 0;
    stack<int> lists;
    for (int i = tmp.length() - 1; i >= 0; i--) {
      if (tmp[i] == ' ')
        continue;
      if (isdigit(tmp[i])) {
        int value = 0;
        while (isdigit(tmp[i])) {
          value = value*10 + tmp[i] - '0';
          i--;
        }
        i++;
        lists.push(value);
      } else {
        if (lists.size() < 2) {
          illegal = true;
          break;
        }
        int op1 = lists.top();
        lists.pop();
        int op2 = lists.top();
        lists.pop();

        switch (tmp[i]) {
        case '+':
          lists.push(op1 + op2);
          break;
        case '-':
          lists.push(op1 - op2);
          break;
        case '*':
          lists.push(op1 * op2);
          break;
        case '/':
          lists.push(op1 / op2);
          break;
        case '%':
          lists.push(op1 % op2);
          break;
        default:
          break;
        }
      }
    }
    if (illegal || lists.size() != 1)
      cout << "illegal" << endl;
    else
      cout << lists.top() << endl;
  }
}

