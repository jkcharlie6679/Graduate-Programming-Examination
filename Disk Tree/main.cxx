/*
 * # Disk Tree
 *
 * Time Limit: 1 sec
 *
 * ## Description
 * 
 * Hacker Bill has accidentally lost all the information from his workstation's hard drive and he has no backup copies of its contents. He does not regret for the loss of the files themselves, but for the very nice and convenient directory structure that he had created and cherished during years of work. Fortunately, Bill has several copies of directory listings from his hard drive. Using those listings he was able to recover full paths (like "WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86") for some directories. He put all of them in a file by writing each path he has found on a separate line. Your task is to write a program that will help Bill to restore his state of the art directory structure by providing nicely formatted directory tree.
 *
 * ## Input
 *
 * The first line of the input file contains single integer number N (1 <= N <= 500) that denotes a total number of distinct directory paths. Then N lines with directory paths follow. Each directory path occupies a single line and does not contain any spaces, including leading or trailing ones. No path exceeds 80 characters. Each path is listed once and consists of a number of directory names separated by a back slash ("\").
 *
 * Each directory name consists of 1 to 8 uppercase letters, numbers, or the special characters from the following list: exclamation mark, number sign, dollar sign, percent sign, ampersand, apostrophe, opening and closing parenthesis, hyphen sign, commercial at, circumflex accent, underscore, grave accent, opening and closing curly bracket, and tilde ("!#$%&'()-@^_`{}~").
 *
 * ## Output
 *
 * Write to the output file the formatted directory tree. Each directory name shall be listed on its own line preceded by a number of spaces that indicate its depth in the directory hierarchy. The subdirectories shall be listed in lexicographic order immediately after their parent directories preceded by one more space than their parent directory. Top level directories shall have no spaces printed before their names and shall be listed in lexicographic order. See sample below for clarification of the output format.
 *
 * ## Reference
 *
 * Source: http://uva.onlinejudge.org/external/15/1556.html
 * Keyword: 
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node {
  string name;
  map<string, int> next;
  Node(string s): name(s) {
    next.clear();
  }
};

void string_split (vector<string> &nodes, string s, string target) {
  while (s.find(target) < s.length()) {
    string node = s.substr(0, s.find(target));
    nodes.push_back(node);
    s.erase(0, s.find(target)+target.length());
  }
  nodes.push_back(s);
}

void insert_tree (vector<Node> &Tree, vector<string> s, int &tree_size) {
  int uid = 0;
  for (int i = 0; i < s.size(); i++) {
    if (Tree[uid].next.find(s[i]) == Tree[uid].next.end()) {
      Tree.push_back(Node {s[i]});
      Tree[uid].next[s[i]] = tree_size++;
    }
    uid = Tree[uid].next[s[i]];
  }
}

void dfs (vector<Node> &Tree, int uid, int depth) {
  if (uid) {
    for (int i = 1; i < depth; i++)
      cout << " ";
    cout << Tree[uid].name << endl;
  }
  for (auto it = Tree[uid].next.begin(); it != Tree[uid].next.end(); it++) {
    dfs(Tree, it->second, depth+1);
  }
}

int main (int argc, char** argv) {
  int n = 0;
  while (scanf("%d", &n) == 1) {
    int tree_size = 1;
    vector<Node> Tree;
    Tree.push_back(Node {"\\"});
    for (int i = 0; i < n; i++) {
      string path;
      vector<string> tmp;
      cin >> path;
      string_split(tmp, path, "\\");
      insert_tree(Tree, tmp, tree_size);
    }
    dfs(Tree, 0, 0);
    cout << endl;
  }
  return 0;
}
