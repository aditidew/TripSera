#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



bool rotateString(string s, string goal) {
        if(s.length()!= goal.length()) return false;

        string dou= s + s;
        if(dou.find(goal) == string::npos){
            return false;
        }
        return true;
    }


int main(){
    string s= "aditi";
    string goal= "itiad";

    cout<< rotateString(s,goal);
    return 0;
}    