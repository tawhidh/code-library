#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a; int b; cin >> a >> b;
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    ans = (ans * 10LL % b + (a[i] - '0')) % b;
  }
  // ans = a % b;
  if (ans == 0) {
    cout << "a is divisible by b\n";
  } else {
    cout << "sad\n";
  }
  return 0;
}
