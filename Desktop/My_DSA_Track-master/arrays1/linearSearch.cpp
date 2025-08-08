#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int search(vector<int> &arr, int n,int num){
    int i;
    for(i=0; i<n;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> arr= {3,4,6,8,1,5,0};
    int n=7;
    int num= 8;
    cout<< "the given num is present at index:" << search(arr,n, num);
    return 0;
}