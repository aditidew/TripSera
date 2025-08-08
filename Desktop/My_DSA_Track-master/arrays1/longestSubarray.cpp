#include <iostream>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> prefixSum(n);
    
    // Build the prefix sum array
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    int maxLen = 0;

    // Check all subarrays using prefix sums
    // Loop through all possible subarrays
for (int start = 0; start < n; start++) {
    for (int end = start; end < n; end++) {
        // Calculate the sum of subarray from 'start' to 'end'
        int currentSum = (start == 0) ? prefixSum[end] : (prefixSum[end] - prefixSum[start - 1]);

        // If the sum equals k, update maxLen
        if (currentSum == k) {
            int length = end - start + 1;
            maxLen = max(maxLen, length);
        }
    }
}

    return maxLen;
}

int main() {
    vector<int> arr = {2, 3, 5, 1, 9};
    int k = 10;
    cout << "Length of longest subarray with sum  " << k << " includes elements: "
         << longestSubarrayWithSumK(arr, k) << endl;
    return 0;
}
