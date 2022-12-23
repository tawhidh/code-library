#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r) {
  int pivot = a[l];
  int i = l, j = r;
  while (i < j) {
    while (a[i] <= pivot) i++;
    while (a[j] > pivot) j--;
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void quickSort(int a[], int l, int r) {
  if (l < r) {
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int a[] = {-2, 45, 0, 11, 5};
  int n = sizeof(a) / sizeof(a[0]);
  quickSort(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}
