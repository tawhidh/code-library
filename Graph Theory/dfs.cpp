#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
bool vis[N];

void dfs(int src) {
  vis[src] = true;
  for (auto v: g[src]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << "unvisited\n";
    } else cout << "visited\n";
  }
  return 0;
}
