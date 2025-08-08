#include<iostream>
#include<climits>
#include<vector>
#include <algorithm>
using namespace std;


 int largestElement(const vector<int> &arr){
    int largest= INT_MIN; //allocating largest with the minimum number
    int n= arr.size();
    for(int i= 0; i<n ; i++){
        if(arr[i]>largest){
            largest= arr[i];

        }
    }
    cout<< "The largest Element in the array is:";
    return largest;
}
int secondLargestElement( const vector<int> &arr){
    int largest= INT_MIN;
    int slargest= INT_MIN;
    int n= arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]> largest){
            slargest= largest;
            largest= arr[i];

        }

        else if(arr[i]< largest && arr[i]> slargest){
            slargest= arr[i];

        }
    }
    cout<< " The second largest element of the array is:";
    return slargest;
}
int kthLargestElement(vector<int> &arr, int k) {
    int n= arr.size();
    sort(arr.begin(), arr.end()); // sorting in ascending order
    cout << k << "th largest value is: ";
    return arr[n - k];   // k-th largest from end
}


 int main() {
    vector<int> arr = {10, 324, 45, 90, 87};
    int k= 4;
    cout<< largestElement(arr) << endl;
    cout<< secondLargestElement(arr) <<endl;
    cout<< kthLargestElement(arr, k);
    return 0;
}