//the pen ->>> pen the
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string reverseAll(string s){
    reverse(s.begin(), s.end());

    int n = s.size();
    int start = 0;

    // Step 2: Reverse each word back to normal
    for (int i = 0; i <= n; i++) {
        // When we find space or end of string, reverse the word
        if (i == n || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }

    return s;
}

int main() {
    string str = "Here is the Pen!";
    cout<< "Original String: " << str<< endl;
    cout << "Reversed Words: " << reverseAll(str)<< endl;  
    return 0;
}