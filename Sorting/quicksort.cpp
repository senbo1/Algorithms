#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high) {
  // Take a pivot element 
  int pivot = arr[low], i = low, j = high;

  while (i < j) {
    while (arr[i] <= pivot && i < high) {
      i++;
    }

    while(arr[j] > pivot && j > low) {
      j--;
    }

    if (i >= j) break; // if Pointers have crossed
    swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int j = partition(arr, low, high);
    quick_sort(arr, low, j - 1);
    quick_sort(arr, j + 1, high);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int arr[] = { 7, 2, 1, 6, 8, 5, 3, 4 };
  int size = sizeof(arr) / sizeof(arr[0]);

  random_device rd; // random seed
  mt19937 g(rd()); // random number engine using the above seed

  std::shuffle(arr, arr + size, g);

  quick_sort(arr, 0, size - 1);
  
  for (int i:arr) {
    cout << i << " ";
  }
}

// Analysis

// Pseudocode 
/* 
  Repeat until i and j cross
  scan i from left to right as long as its smaller than or equal to pivot
  scan j from right to left as long as its larger than pivot
  Exchange a[i] with a[j] if i and j haven't crossed

  When i and j cross 
  swap pivot with a[j] 
  because a[j] is either smaller or equal to pivot while a[i] is larger than pivot
  return j or the new position of pivot back

  call quicksort on left and right side of pivot recursively
*/

// O(n^2) if array is already sorted, shuffle is a good measure before sorting
// O(nlogn) average case
// space (logn) 
// quick sort is in-place(no extra array needed unlike mergesort) but not stable 😔
