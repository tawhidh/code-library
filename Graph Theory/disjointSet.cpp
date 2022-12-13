#include<bits/stdc++.h>
using namespace std;

#define mx 100

int parent[mx];

// void makeSet(int u)
void init();
int Find(int u);
void Union(int u, int v);
bool isFriend(int u, int v);

int main() {
  init();
  Union(1, 2);
  Union(2, 3);
  Union(3, 4);
  Union(4, 5);
  Union(5, 6);
  Union(6, 7);
  Union(7, 8);

  // Union(7, 8);
  // Union(6, 7);
  // Union(5, 6);
  // Union(4, 5);
  // Union(3, 4);
  // Union(2, 3);
  // Union(1, 2);
  

  return 0;
}

// void makeSet(int u) {
//   parent[u] = u;
// }

void init() {
  for (int i = 1; i <= 8; i++) {
    parent[i] = i;
  }
}

int Find(int u) {
  return (u == parent[u]) ? u : parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
  int p = Find(u);
  int q = Find(v);
  if (p != q) parent[q] = p;
}

bool isFriend(int u, int v) {
  int p = Find(u);
  int q = Find(v);
  return p == q;
}