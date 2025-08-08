//how many times, a part of the string has occured in the original string. eg. str: abcbbaabcbc, part: abc, string after removing the occurence: bb
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcbbaabcbc";
    string part = "abc";
    int count = 0;

    // Keep finding and erasing "part" until it's gone
    while (s.find(part) != string::npos) {
        s.erase(s.find(part), part.length());
        count++;
    }

    cout << "Final string: " << s << "\n";
    cout << "Removed " << count << " times\n";
    return 0;
}
