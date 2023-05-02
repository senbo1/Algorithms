#include <bits/stdc++.h>

using namespace std;

int my_binary_search(int arr[], int low, int high, int number) {
  while(low <= high) {
    
    int mid = low + (high - low) / 2;
    
    if(number == arr[mid]) {
      return mid;
    } else if (number > arr[mid]) {
      low = mid + 1;      
    } else if (number < arr[mid]) {
      high = mid - 1;
    }
    
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int arr[5] = {1, 2, 3, 4, 5};

  int length = sizeof(arr) / sizeof(arr[0]);

  cout << my_binary_search(arr, 0, length - 1, 3) << "\n";
}


