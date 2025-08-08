#include <bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &arr) {
    int num = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != num) {
            return num;
        }
        num++;
    }
    return 1; // if last number is missing
}

int main() {
    vector<int> arr = {1, 2, 4};  // Missing 3
    cout << "Missing number is: " << missingNum(arr) << endl;
    return 0;
}
