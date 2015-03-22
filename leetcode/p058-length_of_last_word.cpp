/*
58
Length of Last Word
https://leetcode.com/submissions/detail/23649224/


Given a string s consists of upper/lower-case alphabets and empty space 
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space 
characters only.

For example, 
Given s = "Hello World",
return 5.

(EASY) String
*/

/*
Each time we encounter a new word (non-space char) we need to clear the 
counter. It is done by checking if the last char is ' ' when we meet a 
non-space char. We don't clear the counter when we meet a space char so that 
when there are several spaces at the end of the string, the last word still 
has its counter maintained.

For the language part, a NULL pointer is used for 'last_c' when there is no 
last char. In this case we need to check if it is NULL before dereference it.
Also, remember the 'const' when declaring a pointer that is going to be copied 
with a 'const char*'.

An alternate form of checking last_c is to copy the character and save, which 
should be a little slower:

class Solution {
public:
    int lengthOfLastWord(const char *s) {
            int result = 0;
            char last_c = 0;
            while (*s != 0) {
                if (*s != ' ') {
                    if (last_c == ' ') result = 0;
                    result++;
                }
                last_c = *s++; // note the bad style
            }
            return result;
    }
};


59 / 59 test cases passed.
Status: Accepted
Runtime: 4 ms
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
            int result = 0;
            const char *last_c = 0; // remember the const
            while (*s != 0) {
                if (*s != ' ') {
                    if (last_c && *last_c == ' ') result = 0;
                    result++;
                }
                last_c = s++;
            }
            return result;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLastWord("Hello World") << endl;
}
