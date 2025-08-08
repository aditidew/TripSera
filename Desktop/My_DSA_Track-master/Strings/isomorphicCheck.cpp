#include <iostream>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    int mapS[256] = {0}; // s[i] → t[i]
    int mapT[256] = {0}; // t[i] → s[i]

    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i];
        char c2 = t[i];

        // Check if they’ve been mapped before
        if (mapS[c1] == 0 && mapT[c2] == 0) {
            // First-time mapping
            mapS[c1] = c2;
            mapT[c2] = c1;
        } else {
            // Already mapped: check consistency
            if (mapS[c1] != c2 || mapT[c2] != c1)
                return false;
        }
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    cout << (isIsomorphic(s, t) ? "true" : "false") << endl;
    return 0;
}
