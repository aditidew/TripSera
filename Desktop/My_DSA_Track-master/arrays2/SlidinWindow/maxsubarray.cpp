#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> elements;
        long long current_sum = 0;
        long long max_sum = 0;
        int begin = 0;
        
        for (int end = 0; end < n; end++) {
            if (elements.find(nums[end]) == elements.end()) {
                current_sum += nums[end];
                elements.insert(nums[end]);
                
                if (end - begin + 1 == k) {
                    max_sum = max(max_sum, current_sum);
                    current_sum -= nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
            } else {
                while (nums[begin] != nums[end]) {
                    current_sum -= nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
                begin++; // Skip the duplicate
            }
        }
        
        return max_sum;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    long long result = sol.maximumSubarraySum(nums, k);
    cout << "Maximum sum of subarray with " << k << " distinct elements: " << result << endl;

    return 0;
}