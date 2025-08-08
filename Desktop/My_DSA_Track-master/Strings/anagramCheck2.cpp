#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isAnagram(string s1, string s2){

   s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
   s2.erase(remove_if(s2.begin(), s2.end(), ::isspace), s2.end());

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1.length()!=s2.length()){ return false;}

        int freq[26]={0};
        for(int i=0; i<s1.length(); i++){
           freq[s1[i]-'a']++;
        }
        for(int i=0; i<s2.length(); i++){
           freq[s2[i]-'a']--;
        }
        for(int i=0; i<26;i++)
        if(freq[i]!=0){
            return false;
        }
    
    return true;
}

int main(){
    string s1= "adiit";
    string s2= "ditia ";

    cout<<isAnagram(s1,s2);
    return 0;
}