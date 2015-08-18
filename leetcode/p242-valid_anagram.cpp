/*
242
Valid Anagram
https://leetcode.com/problems/valid-anagram/


Description:

Given two strings s and t, write a function to determine if t is an anagram of 
s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

(EASY) Hash Table, Sort
Similar Problems: 49 Group Anagrams
*/

/*
SOLUTION: (Hash Map with Array)

Tips:
- An anagram is an rearrangement of the letters. So each letter should have 
the same occurrences.
- Use a hash map to count "char : count". Check the difference.

[3m]
32 / 32 test cases passed.
Status: Accepted
Runtime: 12 ms
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int map[26];
        for (int i = 0; i < 26; ++i) map[i] = 0;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (map[i] != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isAnagram("anagram", "nagaram");
 
    return 0;
}
