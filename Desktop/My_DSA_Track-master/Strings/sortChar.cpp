#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string freqSort(string s) {
    int freq[26] = {0};

    // Step 1: Count frequency of each lowercase character
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Store characters that appear at least once
    vector<char> chars;
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            chars.push_back((char)(i + 'a'));
        }
    }

    // Step 3: Sort characters by frequency using custom comparator
    sort(chars.begin(), chars.end(), [&](char a, char b) {
        return freq[a - 'a'] > freq[b - 'a'];
    });

    // Step 4: Build the result string
    string result = "";
    for (int i = 0; i < chars.size(); i++) {
        char c = chars[i];
        for (int j = 0; j < freq[c - 'a']; j++) {
            result += c;
        }
    }

    return result;
}

int main() {
    string s = "tree";
    string sorted = freqSort(s);
    cout << sorted << endl;  // Output: eetr or eert
    return 0;
}
