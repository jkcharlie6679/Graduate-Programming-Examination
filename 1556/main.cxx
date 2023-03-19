/*
 * Disk Tree
 * Source: http://uva.onlinejudge.org/external/15/1556.html
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
