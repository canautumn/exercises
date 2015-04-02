/*
125
Valid Palindrome
https://leetcode.com/problems/valid-palindrome/


Given a string, determine if it is a palindrome, considering only alphanumeric 
characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to 
ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


(EASY) Two Pointers, String
*/

/*
Tips: 
If '&&' and '||' are written in the same pair of parentheses, clang will issue 
a warning like below, to improve the readability, '&&' should be put inside 
a pair of parentheses before joining '||', since '&&' has higher priority, 
which could be forgotten. (Or suppress the warning to insist the style.)
    warning: '&&' within '||' [-Wlogical-op-parentheses]

Instead of writing the logic using ASCII code calculation, standard C 
functions 'isalnum' and 'tolower' can be used. See below:

SOLUTION (ALTERNATIVE):
( https://leetcode.com/discuss/29574/passed-clean-c-code )
bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;
    while(start < end) {
        if (!isalnum(s[start])) start++;
        else if (!isalnum(s[end])) end--;
        else {
            if (tolower(s[start++])!=tolower(s[end--])) return false;
        }
    }
    return true;
}

LEETCODE SOLUTION: 
O(n) runtime, O(1) space:
The idea is simple, have two pointers – one at the head while the other one at 
the tail. Move them towards each other until they meet while skipping 
non-alphanumeric> characters.

475 / 475 test cases passed.
Status: Accepted
Runtime: 19 ms
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static inline bool isAlphanumeric(char c) {
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z')) return true; else return false;
    }
    bool isPalindrome(string s) {
        if (!s.size()) return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isAlphanumeric(s[i])) {
                i++;
                continue;
            }
            if (!isAlphanumeric(s[j])) {
                j--;
                continue;
            }
            if ((s[i] >= 'A' && s[i] <= 'Z' && s[i] == s[j] - ('a' - 'A')) ||
                (s[i] >= 'a' && s[i] <= 'z' && s[i] == s[j] + ('a' - 'A')) ||
                (s[i] == s[j])) {
                i++;
                j--;
                continue;
            }
            return false;            
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << 
            solution.isPalindrome("race a car") << endl;
    return 0;
}
