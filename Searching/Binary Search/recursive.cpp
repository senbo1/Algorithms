#include <bits/stdc++.h>

using namespace std;

int recursive_binary_search(int arr[], int low, int high, int target) {
  if (low <= high) {
    int mid = low + (high - low) / 2;

    if (target == arr[mid]) {
      return mid;
    } else if (target > arr[mid]) {
      return recursive_binary_search(arr, mid + 1, high, target);
    } else if (target < arr[mid]) {
      return recursive_binary_search(arr, low, mid - 1, target);
    }
  } 

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int arr[5] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << recursive_binary_search(arr, 0, size - 1, 5);
  return 0;
}


