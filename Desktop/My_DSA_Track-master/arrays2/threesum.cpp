#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void threeSumPrint(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < target) {
                j++;
            } else if (sum > target) {
                k--;
            } else {
                // Print the triplet directly
                cout << "[" << arr[i] << ", " << arr[j] << ", " << arr[k] << "] ";
                j++;
                k--;

                // Skip duplicates for the second and third elements
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int target = 0;

    threeSumPrint(arr, target);

    return 0;
}
