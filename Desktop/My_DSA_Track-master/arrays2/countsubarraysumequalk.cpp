
#include <bits/stdc++.h>
using namespace std;

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum[n + 1];
        prefixSum[0] = 0;

        // Build prefix sum array
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Brute-force check all subarrays using prefix sums
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = prefixSum[j + 1] - prefixSum[i];
                if(sum == k) {
                    count++;
                }
            }
        }

        return count;
    }

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = subarraySum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

