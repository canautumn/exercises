/*
3
Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/


Given a string, find the length of the longest substring without repeating 
characters. For example, the longest substring without repeating letters for 
"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring 
is "b", with the length of 1.


(MEDIUM) Hash Table, Two Pointers, String
*/

/*
Optimization 2 (Using array as char hash map):

In this simple case, an array / vector could be used as a hash map for chars, 
to avoid the overhead of unordered_map.

Using char value as the hash function, a vector of 256 integers can be used. 
Other part of the code is not changed, except for that if the vector is 
initialized to -1, there is no need to check the existence of a key. (-1 is 
automatically included in the 'else' condition. 0 will not work, since 0 is a 
valid case when the first char of the string is put into the hash map.)

This improves the running time from ~70ms to ~20ms.


981 / 981 test cases passed.
Status: Accepted
Runtime: 20 ms
*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charset(256, -1);
        int result = 0, counter = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (charset[c] >= i - counter) {
                result = max(result, counter);
                counter = i - charset[c];
            } else {
                counter++;
            }
            charset[c] = i;
            if (i - counter + result >= (int)s.size()) break;
        }
        return max(result, counter);
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbbb") << endl;
    cout << solution.lengthOfLongestSubstring("abcabcd") << endl;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << solution.lengthOfLongestSubstring("dvdf") << endl;
    cout << solution.lengthOfLongestSubstring("abba") << endl;
    cout << solution.lengthOfLongestSubstring("c") << endl;
    return 0;
}
