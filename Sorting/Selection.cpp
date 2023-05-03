#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int N) {
    for(int i = 0; i < N - 1; i++) {
        int min = i;
        for(int j = i + 1; j < N; j++) {
            if (arr[j] < arr[min]) {
                min = j;  
            }
        }
        if (i != min) {
            swap(arr[i], arr[min]);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A[] = { 3, 1, 4, 99, 23, 44, 169 };
    int len = sizeof(A) / sizeof(A[0]);
    selection_sort(A, len);

    for (int i:A) {
        cout << i << " ";
    }
}

/*
    Time Complexity
    N^2/2 Compares and Exchanges
    summary - select the smallest element from the unsorted array and move it to sorted array
                maintaining pointer for minimum and current index 
*/