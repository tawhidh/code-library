#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(a[minIndex], a[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int a[] = {-2, 45, 0, 11, 5};
  int n = sizeof(a) / sizeof(a[0]);
  selectionSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}
