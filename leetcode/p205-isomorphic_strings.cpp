/*
205
Isomorphic Strings
https://leetcode.com/problems/isomorphic-strings/


Description:

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same 
character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

(EASY) Hash Table
Similar Problems: 
*/

/*
SOLUTION: Hash Table (One to record char mapping, one to ensure exclusive 
mapping) (C-style array implemented hash table)

- A hash table (256 char buckets) is enough to record a char mapping relation.
- To ensure exclusive mapping (No two characters may map to the same character), 
use another hash table (256 bool buckets) to label whether a destination char 
has been mapped or not.

Tips:
- Read the question carefully. "No two characters may map to the same 
character" needs to be taken care of.

[5m*]
30 / 30 test cases passed.
Status: Accepted
Runtime: 8 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        char * table = new char[256];
        bool * mapped = new bool[256];
        for (int i = 0; i < 256; ++i) {
            table[i] = 0;
            mapped[i] = false;
        }
        for (int i = 0; i < s.size(); ++i) {
            char p = s[i], q = t[i];
            if (table[p] == 0) {
                if (mapped[q]) return false;
                table[p] = q;
                mapped[q] = true;
                continue;
            }
            if (table[p] != q) return false;
        }
        delete[] table;
        delete[] mapped;
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isIsomorphic("ab", "aa");
    
    return 0;
}
