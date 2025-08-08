#include <bits/stdc++.h>
using namespace std;

void maxSubarraySumWithPrint(int arr[], int n) {
    long long maxSum = arr[0], currentSum = arr[0];
    int start = 0, end = 0, s = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > currentSum + arr[i]) {
            currentSum = arr[i];
            s = i;  // potential start of new subarray
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = s;
            end = i;
        }
    }

    // Output
    cout << "The maximum subarray sum is: " << maxSum << endl;
    cout << "The subarray is: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, -1, 2, 2}; // Change this for different test cases
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSubarraySumWithPrint(arr, n);
    return 0;
}
