/*
 * (c) 2023 - Topcoder.com - public domain at https://www.topcoder.com/thrive/articles/eulerian-path-and-circuit-in-graphs
 */


#include<bits/stdc++.h>

using namespace std;

map < int, vector < int >> graph;
vector < int > path;
vector < int > in, out;
int edges;
int n;

void setUp() {
  in.resize(n);
  out.resize(n);

  edges = 0;

  for (int from = 1; from < n; from++)
    for (auto to: graph[from]) {
      in [to]++, out[from]++;
      edges++;
    }
}

bool hasEulerianPath() {
  if (edges == 0) return false;

  int startNodes = 0, endNodes = 0;

  for (int i = 0; i < n; i++) {
    if (out[i] - in [i] > 1 || in [i] - out[i] > 1) return false;
    else if (out[i] - in [i] == 1) startNodes++;
    else if (in [i] - out[i] == 1) endNodes++;
  }

  return (endNodes == 0 && startNodes == 0) || (endNodes == 1 && startNodes == 1);
}

int findStartNode() {
  int start = 0;

  for (int i = 0; i < n; i++) {
    if (out[i] - in [i] == 1) return i;
    if (out[i] > 0) start = i;
  }
  return start;
}

void dfs(int at) {
  while (out[at]) {
    int next = graph[at][--out[at]];
    dfs(next);
  }
  path.push_back(at);
}

vector < int > getEulerianPath() {
  setUp();

  if (!hasEulerianPath()) return {};

  dfs(findStartNode());

  if (path.size() != edges + 1) return {};

  reverse(path.begin(), path.end());
  return path;
}

void addEdge(int from, int to) {
  graph[from].push_back(to);
}

int main() {

  n = 7;

  addEdge(1, 2);
  addEdge(1, 3);
  addEdge(2, 2);
  addEdge(2, 4);
  addEdge(2, 4);
  addEdge(3, 1);
  addEdge(3, 2);
  addEdge(3, 5);
  addEdge(4, 3);
  addEdge(4, 6);
  addEdge(5, 6);
  addEdge(6, 3);

  vector < int > path = getEulerianPath();

  for (auto x: path) cout << x << " ";
}
