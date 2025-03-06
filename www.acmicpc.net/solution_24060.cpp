#include <iostream>

using namespace std;

int count = 0;

void init();
void merge_sort(int *arr, int left, int right, int K);
void merge(int *arr, int p, int q, int r, int K);
int main() {

  init();

  int n, k;
  cin >> n >> k;

  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  merge_sort(arr, 0, n - 1, k);
  if(count<k) cout << -1 << '\n';
  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void merge_sort(int *arr, int left, int right, int k) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid, k);
    merge_sort(arr, mid + 1, right, k);
    merge(arr, left, mid, right, k);
  }
}

void merge(int *arr, int left, int mid, int right, int k) {
  int i = left, j = mid + 1, t = 1;
  int temp[right + 2];

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[t++] = arr[i++];
    } else {
      temp[t++] = arr[j++];
    }
  }

  while (i <= mid) {
    temp[t++] = arr[i++];
  }

  while (j <= right) {
    temp[t++] = arr[j++];
  }

  i = left, t = 1;
  while (i <= right) {
    arr[i++] = temp[t++];
    if (++count == k) {
      cout << temp[t - 1] << '\n';
    }
  }
}