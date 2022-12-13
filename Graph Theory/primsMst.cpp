#include<bits/stdc++.h>
using namespace std;
#define mx 105

struct Node {
  int value;
  int cost;
};

vector<Node> graph[mx];
bool visited[mx];

class cmp {
public:
  bool operator() (Node a, Node b) {
    if (a.cost > b.cost) return true;
    return false;
  }
};

int primsMst(int source);

int main() {
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  cout << "Enter source: ";
  int source;
  cin >> source;
  cout << primsMst(source) << endl;

  return 0;
}

int primsMst(int source) {
  priority_queue<Node, vector<Node>, cmp> pq;
  int sumOfMst = 0;
  pq.push({source, 0});
  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();

    int val = current.value;
    int cost = current.cost;
    if (!visited[val]) {
      visited[val] = true;
      sumOfMst += cost;
      for (Node next : graph[val]) {
        int nextVal = next.value;
        int nextCost = next.cost;
        if (!visited[nextVal]) pq.push({nextVal, nextCost});
      }
    }
  }
  return sumOfMst;
}