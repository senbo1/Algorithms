#include <bits/stdc++.h>

using namespace std;

void shell_sort(int arr[], int N) {
  
  int h = 1;
  while (h < N/3) h = 3*h + 1;

  while(h >= 1) {
    for (int i = h; i < N; i++) {
      for (int j = i; j >= h && arr[j] < arr[j-h]; j -= h) {
        swap(arr[j], arr[j-1]);
      }
    }
    
    h = h / 3;

  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int arr[] = { 3, 2, 5, 6, 9, 4, 1, 8, 7, 10, 10,2 };
  int N = sizeof(arr) / sizeof(arr[0]);
  shell_sort(arr, N);

  for (int i:arr) {
    cout << i << " ";
  }
}

// Worst Case:- O(N^3/2)
// Move entries more than one position at a time by h-sorting the array