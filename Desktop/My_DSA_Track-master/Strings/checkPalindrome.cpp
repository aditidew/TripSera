#include <iostream>
#include <string>
#include <cctype>  // for isalnum, tolower
using namespace std;

bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        if (!isalnum(s[left])) {
            left++;
            continue;
        }
        if (!isalnum(s[right])) {
            right--;
            continue;
        }

        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        // Move pointers towards the center
        left++;
        right--;
    }

    return true;
}

int main() {
    string input = "A man, a plan, a canal: Panama";
    cout << (isPalindrome(input) ? "Yes, palindrome\n" : "No, not palindrome\n");
    return 0;
}
