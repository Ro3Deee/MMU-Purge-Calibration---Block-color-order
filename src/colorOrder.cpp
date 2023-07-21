/*
 * (c) 2023 - Topcoder.com - public domain at https://www.topcoder.com/thrive/articles/eulerian-path-and-circuit-in-graphs
 * (C) 2023 Petru Becheru
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * T his program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANT*ABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
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

  if (!hasEulerianPath()) {
    cout<<edges<<"edges. the graph is not eulerian\n";
    return {};
  }

  // cout<<findStartNode(); return {};
  // dfs(findStartNode());
  dfs(1);
  
  if (path.size() != edges + 1) {
    cout<<"\nthe path is not ok:\n";
    for (auto x: path) cout << (x+1) << " ";
    return {};
  }

  reverse(path.begin(), path.end());
  return path;
}

void addEdge(int from, int to) {
  graph[from].push_back(to);
}

int main() {

  cout<<"\nNumber of colors: ";
  cin>>n;
  ++n;
  
  // cout<<"graf:\n";
  for(int i=n-1;i--;)
    for(int j=i;j--;){
      addEdge(i+1, j+1);
      addEdge(j+1, i+1);
      // cout<<i+1<<" "<<j+1<<"\n";
      // cout<<j+1<<" "<<i+1<<"\n";
    }
      

  vector < int > path = getEulerianPath();

  int deplasament=0;
  if(path.size()){
    cout<<"\n Colors :\n";
    int prev=0;
    for (auto x: path){
      if(prev){
        cout<<"Gradient: "<<prev+deplasament<<" » "<<x+deplasament<<". Block color: "<<x+deplasament<<"\n";
      }
      prev=x;
    }
    
    }
  
  cout<<"\n\n";

  return 0;
}
