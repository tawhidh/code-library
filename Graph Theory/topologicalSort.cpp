#include<bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
bool vis[N];
vector<int> ans;

void dfs(int src) {
  vis[src] = true;
  for (auto v: g[src]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
  ans.push_back(src);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
