#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fourSumPrint(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            // Skip duplicates for the second element
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];

                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    cout << "[" << arr[i] << ", " << arr[j] << ", " << arr[left] << ", " << arr[right] << "] ";
                    left++;
                    right--;

                    // Skip duplicates for third and fourth elements
                    while (left < right && arr[left] == arr[left - 1]) left++;
                    while (left < right && arr[right] == arr[right + 1]) right--;
                }
            }
        }
    }
}

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    fourSumPrint(arr, target);

    return 0;
}
