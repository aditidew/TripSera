#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> moveZeros(vector<int> &arr){
    int n=arr.size();
    int endp=n-1; 
    for (int j = 0; j <= endp;j++ ) {
        if (arr[j] == 0) {
            swap(arr[j], arr[endp]);
            endp--;
            // Don't increment j here, since the new value at j might also be zero
        }
        }
        return arr;
}


int main(){
    vector<int> nums= {1,0,0,1,1,1};
     vector<int> result = moveZeros(nums);
    cout << "After Moving all zeors to end ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
