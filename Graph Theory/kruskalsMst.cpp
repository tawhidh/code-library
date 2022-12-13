#include<bits/stdc++.h>
using namespace std;
#define mx 1001

class Edge {
public:
  int u, v, w;
  Edge(int u, int v, int w) {
    this->u = u;
    this->v = v;
    this->w = w;
  }
  bool operator < (const Edge a) const {
    return w < a.w;
  }
};

vector<Edge> graph;
int parent[mx];

int Find(int u) {
  return (u == parent[u]) ? u : Find(parent[u]);
}

int kruskalsMst(int nodes) {
  sort(graph.begin(), graph.end());
  for (int i = 0; i < nodes; i++) {
    parent[i] = i;
  }

  int countEdge = 0, totalWeight = 0;
  for (int i = 0; i < graph.size(); i++) {
    Edge target = graph[i];
    int u = Find(target.u);
    int v = Find(target.v);
    if (u != v) {
      parent[u] = v;
      countEdge++;
      totalWeight += target.w;
      if (countEdge == nodes - 1) break;
    }
  }
  return totalWeight;
}

int main() {
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph.push_back({u, v, w});
  }
  cout << kruskalsMst(nodes) << endl;
  return 0;
}

/*
input

14 14
8 2 2
2 5 4
0 1 4
2 3 7
7 6 1
6 5 2
8 6 6
3 5 14
5 4 10
7 8 7
0 7 8
1 2 8
3 4 9
1 7 11

expected output: 37
*/