#include <bits/stdc++.h>

using namespace std;

#define CUTOFF 15;

void insertion_sort(int arr[], int low, int high) {
  for (int i = low; i <= high; i++) {
    for (int j = i; j > low; j--) {
      if(arr[j] < arr[j-1]) {
        swap(arr[j], arr[j-1]);
      } else break;
    }
  }
}

void merge(int arr[], int low, int mid, int high) {
  int aux[high + 1];

  for (int i = low; i <= high; i++) {
    aux[i] = arr[i];    
  }

  int i = low, j = mid + 1; // Pointer for left and right subarray

  for (int k = low; k <= high; k++) {
    if (i > mid) arr[k] = aux[j++];
    else if (j > high) arr[k] = aux[i++];
    else if (aux[i] < aux[j]) arr[k] = aux[i++];
    else arr[k] = aux[j++]; 
  }
}

void merge_sort(int arr[], int low, int high) {
  if(high <= low + CUTOFF - 1) {
    insertion_sort(arr, low, high); 
    return;
  } 
  
  int mid = low + (high - low) / 2;

  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);
  if (arr[mid] < arr[mid + 1]) return; // Array is already sorted
  merge(arr, low, mid, high);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  int arr[] = { 3, 2, 5, 6, 9, 4, 1, 8, 7, 10, 10,2 };
  int len = sizeof(arr) / sizeof(arr[0]);
  merge_sort(arr, 0, len - 1);

  for (int i:arr) {
    cout << i << " ";
  }
}


// O(NLogN) 
// good for linked list, stable (maintains previous order)
// Not in place takes extra space
// For smaller arrays(N <= 15) Insertion sort is better than merge sort, 