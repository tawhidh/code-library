#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a; int b; cin >> a >> b;
  int x = 0;
  for (int i = 0; i < a.size(); i++) {
    x = (x * 10LL % b + (a[i] - '0')) % b;
  }
  cout << __gcd(x, b);
  return 0;
}

