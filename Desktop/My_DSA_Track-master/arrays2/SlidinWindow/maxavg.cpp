#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        double maxavg = INT_MIN;

        for (int i = 0; i + k <= nums.size(); i++) {
            int windowsum = 0;

            for (int j = i; j < i + k; j++) {
                windowsum += nums[j];
            }

            avg = (double)windowsum / k;
            maxavg = max(avg, maxavg);
        }

        return maxavg;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution sol;
    double result = sol.findMaxAverage(nums, k);

    cout << "Maximum average of subarray of size " << k << " is: " << result << endl;

    return 0;
}
