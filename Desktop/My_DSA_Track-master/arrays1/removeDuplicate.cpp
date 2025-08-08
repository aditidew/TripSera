#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;


vector<int> removeDuplicate(vector<int> &arr){
    int n= arr.size();
    sort(arr.begin(), arr.end());

    int i= 0;
    for(int j=1; j<n; j++){
         if(arr[j]!= arr[i]){
            i++;
            arr[i]= arr[j];
         }
        
    }
    return vector<int>(arr.begin(), arr.begin() + i + 1);
     

}


int main() {
    vector<int> arr = {10, 324, 45, 90, 87, 45, 90};
    vector<int> result = removeDuplicate(arr);

    cout << "After removing duplicates: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}