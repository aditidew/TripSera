#include <iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string longestCommon(vector<string> &str){
    if(str.empty())
    return "";

    string prefix= str[0];
    for(int i=1; i<str.size(); i++){
        while(str[i].find(prefix)!=0){
            prefix= prefix.substr(0, prefix.length()- 1);
            if (prefix.empty()) return "";
    }

}  
return prefix;
}


int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommon(strs) << endl;
    return 0;
}