#include <iostream>
#include <vector>
using namespace std;
//DUTCH NATIONAL FLAG
// Function to sort an array of 0s, 1s and 2s
void sort012(vector<int> &arr) {
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        if (arr[mid] == 0)
            swap(arr[lo++], arr[mid++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[hi--]);
    }
}

int main() {
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();

    sort012(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
return 0;
}