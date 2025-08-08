#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int> &arr){
    int n= arr.size();
    for(int i=0; i< n; i++){
        if(arr[i]> arr[i-1]){
            return true;
        }
        else return false;
    }
}

int main(){
    vector<int> arr = {10, 324, 45, 90, 87};
    cout<< checkSorted(arr);
}