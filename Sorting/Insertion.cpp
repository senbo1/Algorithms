#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int N) {
  
  for (int i = 0; i < N; i++) {
    for (int j = i; j > 0; j--) {
      if (arr[j] < arr[j-1]) {
        swap(arr[j], arr[j-1]);
      }
      else break;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int arr[] = { 3, 2, 5, 6, 9, 4 };
  int len = sizeof(arr) / sizeof(arr[0]);
  insertion_sort(arr, len);

  for (int i:arr) {
    cout << i << " ";
  }

}

/*
  Time Complexity 
  Randomly-ordered Array -> (N^2)/4 compares and exchanges (2x faster than Selection sort)
  Sorted Array in Descending Order -> N^2/2 compares and exchanges (slower than selection sort)
  Sorted Array in Ascending Order -> n - 1 compares and 0 exchanges
  Partially Sorted Arrays -> linear, exchanges = no. of inversions and compares = exchanges + inversions
  Invesion is a pair of key that is out of order
  
  summary - go from left to right comparing each item to its left and "inserting" the item in its correct position
*/