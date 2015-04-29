/*
CtCI Chapter 1 Arrays and Strings
Problem 1 Unique Characters

Implement an algorithm to determine if a string has all unique characters. What 
if you cannot use additional data structures?

(Easy) Hash Table, String
*/

/*
SOLUTION (Hash Table)

- Use STL unordered_set to determine uniqueness;
- If no additional data structures are permitted, use a bool array of size 256 
as the hash table for characters.

*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool unique_characters(string s) {
    unordered_set<char> charset;
    for (char c : s) {
        if (charset.find(c) != charset.end()) return false;
        charset.insert(c);
    }
    return true;
}

bool unique_characters_nostl(string s) {
    bool charset[256];
    for (int i = 0; i < 256; ++i) charset[i] = false;
    for (char c : s) {
        if (charset[c]) return false;
        charset[c] = true;
    }
    return true;
}

int main() {
    cout << unique_characters("abcdefghijklmnopqrstuvwxyz") << endl;
    cout << unique_characters("uniquechars") << endl;
    cout << unique_characters_nostl("abcdefghijklmnopqrstuvwxyz") << endl;
    cout << unique_characters_nostl("uniquechars") << endl;
    return 0;    
}