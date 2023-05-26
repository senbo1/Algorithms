#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int N) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int arr[] = { 3, 2, 5, 6, 9, 4, 1, 8, 7, 10 };
  int N = sizeof(arr) / sizeof(arr[0]);
  bubble_sort(arr, N);

  for (int i:arr) {
    cout << i << " ";
  }
}

// After N-1 passes the array is sorted since every element except the 1st is in the sorted array
// After each pass the largest element bubble up to the end
// Time Complexity - O(N^2)