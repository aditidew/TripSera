#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> temp;
    int x = 0, y = 0;

    while (x < n && y < m) {
        if (arr1[x] == arr2[y]) {
            temp.push_back(arr1[x]);
            x++;
            y++;
        }
        else if (arr1[x] < arr2[y]) {
            temp.push_back(arr1[x]);
            x++;
        }
        else {
            temp.push_back(arr2[y]);
            y++;
        }
    }

    // Add remaining elements
    while (x < n) {
        temp.push_back(arr1[x]);
        x++;
    }
    while (y < m) {
        temp.push_back(arr2[y]);
        y++;
    }

    // Remove duplicates
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    return temp;
} 

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {1, 3, 5, 6};

    vector<int> result = unionArray(a, b);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
