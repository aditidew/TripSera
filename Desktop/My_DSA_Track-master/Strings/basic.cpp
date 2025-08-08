#include <iostream>
#include <cstring>  // For strlen
#include <string>
#include <algorithm>
using namespace std;

int main() {
    char st[] = {'a', 'b', 'c', '\0'};    // char array with null terminator
    int arr[] = {1, 2, 3};                // integer array
    char str[] = "aditi";                // null-terminated string
    char str2[200];      // buffer for input



    string s;
    cout << "Enter your st: ";
    getline(cin, s, '$');  // Correct usage for std::string
    cout << "Output of s: " << s << s.length() << endl;
    reverse(s.begin(), s.end());
    cout<< "Reversed s:" <<s<< endl;


    cout << "Enter your string: ";
    cin.getline(str2, 200, '$');  // Correct usage for char array
    cout << "Output of string: " << str2 << endl;


    cout << str << "  " << strlen(str) << endl;
    cout << arr << "  " << sizeof(arr)/sizeof(arr[0]) << endl;
    cout << st << "  " << strlen(st) << endl;

    return 0;
}
