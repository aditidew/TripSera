#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string largestOdd(string nums){
    for(int i= nums.size()- 1; i>=0; i--){
        if((nums[i] - '0')%2==1){
            return nums.substr(0, i+1);
        }
        

    }
     return "None ";
}

int main(){
    string nums= "4680";
    cout<< largestOdd(nums);

    return 0;
}