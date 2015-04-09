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
It is a two pointer array problem, but not really using two pointers. When you 
find a new char that has been seen before, you want to know what was the 
position you've seen it last time, and that position is the second pointer. 
Therefore, there are actually one and a whole array of pointers you want to 
keep. 

As long as we find the index of the char we've met, we want to remove it and 
all chars before it and in the charset we've seen, but keep all chars that are 
following this old repeated char, and update the max counter (result), as well 
as the counter of current length to that of the chars from the old repeated 
char to the new repeated char. But consider that we don't need to actually 
remove those chars from the set, since we've keep each char's index in the set 
and the current length of the non-repeat-char string. All we need to do is 
changing the condition that "found char in the charset we've seen" to "if the 
index of the char we last saw is larger than current index minus current 
non-repeat-char string's length".

To quickly record and find the index of each char we've seen, we need a hash 
map. 

If the map has the key c, and the value of it is larger than i - counter 
(which means the char is in the current non-repeat-char string), update the 
counter to be current index minus the index of the old char we've seen, since 
you don't have to start all over, but just make the start pointer of the 
current non-repeat-char string to the next position of the char found in the 
map.

Run this algorithm a couple of times in mind and test edge cases.

Tips:
- STL implementation of hash map is unordered_map. However, in this case, we 
could use a simpler data structure -- array, to implement hash maps. See 
Optimization 2.
- You have to check if the key exists in the map. Since operator[] of map will 
return 0 if the key is not in the hash map, but 0 means the char is at 0 in 
our algorithm, which breaks the logic and get wrong result when there is only 
one char in the string. It would be nicer if it returns -1 for non-existed key.

So be careful for edge cases: whether 0 stands for special case or really mean 
something.


981 / 981 test cases passed.
Status: Accepted
Runtime: 68 ms
*/



#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charset;
        int result = 0, counter = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (charset.find(c) != charset.end() && charset[c] >= i - counter) {
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
