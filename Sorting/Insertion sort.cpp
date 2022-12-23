#include<bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int a[] = {-2, 45, 0, 11, 5};
  int n = sizeof(a) / sizeof(a[0]);
  insertionSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}
