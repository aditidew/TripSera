#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twosumAllPairs(const vector<int> &arr, int target) {
    vector<int> nums = arr;  // Make a copy to sort
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum < target) {
            left++;
        } else if (sum > target) {
            right--;
        } else {
            cout << "[" << nums[left] << ", " << nums[right] << "] ";
            left++;
            right--;

            // Skip duplicates
            while (left < right && nums[left] == nums[left - 1]) left++;
            while (left < right && nums[right] == nums[right + 1]) right--;
        }
    }
}

int main() {
    vector<int> arr = {6, 3, 2, 6, 3, 9, -1, 4, -1};
    int target = 5;

    twosumAllPairs(arr, target);

    return 0;
}
