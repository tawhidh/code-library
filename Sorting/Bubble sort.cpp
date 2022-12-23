#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = 0;
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        swapped = 1;
      }
    }
    if (!swapped) break;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int a[] = {-2, 45, 0, 11, 5};
  int n = sizeof(a) / sizeof(a[0]);
  bubbleSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}
