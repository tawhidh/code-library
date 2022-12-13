#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
bool vis[N];
int dis[N];

void bfs(int src) {
  queue<int> q;
  vis[src] = true;
  dis[src] = 0;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v: g[u]) {
      if (!vis[v]) {
        vis[v] = true;
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(0);

  for (int i = 0; i < n; i++) {
    cout << "Distance of node " << i << " : " << dis[i] << "\n";
  }

  return 0;
}
