#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxConsecutive(vector<int> &arr) {
    int count = 0;
    int maxcount = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;
        } else {
            maxcount = max(maxcount, count);
            count = 0;
        }
    }

    // Final update in case array ends with 1s
    return max(maxcount, count);
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int ans = maxConsecutive(nums);
    cout << "The maximum consecutive 1's are " << ans << endl;
    return 0;
}
