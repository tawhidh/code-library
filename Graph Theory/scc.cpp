#include<bits/stdc++.h>
using namespace std;
#define mx 101

bool vis[mx];
bool visited[mx];
vector<int> dGraph[mx];
vector<int> rdGraph[mx];
vector<int> component[mx];
stack<int> sortVal;

int scc(int nodes);
void dfs(int source);
void dfs2(int source, int sccNo);

int main() {
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    dGraph[u].push_back(v);
    rdGraph[v].push_back(u);
  }
  int total = scc(nodes);
  for (int i = 1; i <= total; i++) {
    cout << "connected component no: " << i << " : ";
    for (int comp : component[i]) {
      cout << comp << " ";
    }
    cout <<  endl;
  }

  return 0;
}

void dfs(int source) {
  vis[source] = true;
  for (int next : dGraph[source]) {
    if (!vis[next]) dfs(next);
  }
  sortVal.push(source);
}

void dfs2(int source, int sccNo) {
  component[sccNo].push_back(source);
  visited[source] = true;
  for (int next : rdGraph[source]) {
    if (!visited[next]) dfs2(next, sccNo);
  }
}

int scc(int nodes) {
  int sccNo = 0;
  for (int i = 1; i <= nodes; i++) {
    if (!vis[i]) dfs(i);
  }
  while(!sortVal.empty()) {
    int u = sortVal.top();
    sortVal.pop();
    if (!visited[u]) {
      sccNo++;
      dfs2(u, sccNo);
    }
  }
  return sccNo;
}

/* 
5 5
1 0
0 2
2 1
0 3
3 4
*/