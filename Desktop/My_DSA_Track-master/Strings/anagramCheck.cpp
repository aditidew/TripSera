#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

bool anagramCheck(string s1, string s2){

     s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
    s2.erase(remove_if(s2.begin(), s2.end(), ::isspace), s2.end());

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    
    if(s1.length()!= s2.length()) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    
        return s1==s2;
    
}

int main(){
    string s1= "care ik";
    string s2= "race  ki";
    cout<<anagramCheck(s1,s2);
}