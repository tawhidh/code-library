#include<bits/stdc++.h>
using namespace std;

#define mx 101
#define inf INT_MAX

class Edge {
public:
  int u, v, w;
  Edge(int u, int v, int w) {
    this->u = u;
    this->v = v;
    this->w = w;
  }
};

vector<Edge> graph;

vector<int> bellmanFord(int nodes, vector<Edge> graph, int source) {
  vector<int> dist(nodes + 1, inf);
  dist[source] = 0;
  bool changed = false;
  
  for (int i = 1; i <= nodes; i++) {
    changed = false;
    for (int j = 0; j < graph.size(); j++) {
      if (dist[graph[j].u] < inf) {
        if (dist[graph[j].u] + graph[j].w < dist[graph[j].v]) {
          dist[graph[j].v] = dist[graph[j].u] + graph[j].w;
          changed = true;
        }
      }
    }
    if (!changed) break;
  }
  if (changed) cout << "Negative cycle detected!" << endl;
  return dist;
}

int main() {
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph.push_back({u, v, w});
  }
  cout << "Enter source: ";
  int source;
  cin >> source;
  vector<int> dist = bellmanFord(nodes, graph, source);
  for (int i = 1; i <= nodes; i++) {
    cout << "Distance of node " << i << " : " << dist[i] << endl; 
  }
  return 0;
}