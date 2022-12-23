#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r) {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  int left[n1], right[n2];
  for (int i = 0; i < n1; i++) {
    left[i] = a[l + i];
  }
  for (int j = 0; j < n2; j++) {
    right[j] = a[mid + 1 + j];
  }
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      a[k++] = left[i++];
    } else {
      a[k++] = right[j++];
    }
  }
  while (i < n1) {
    a[k++] = left[i++];
  }
  while (j < n2) {
    a[k++] = right[j++];
  }
}

void mergeSort(int a[], int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int a[] = {-2, 45, 0, 11, 5};
  int n = sizeof(a) / sizeof(a[0]);
  mergeSort(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}
