/*
20
Valid Parentheses
https://oj.leetcode.com/problems/valid-parentheses/


Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.



(EASY)  Stack, String
*/

/*

Corner cases:
- When the first element is ']', and st.top() will be checked, while the stack is empty.
This will cause segment fault (top() doesn't check isEmpty). An easy way to avoid this is
to add a sentinel bottom element '#' and use it instead of 'empty'. In this case the stack
is never really empty so that the illegal access is avoided.

19m
65 / 65 test cases passed.
Status: Accepted
Runtime: 2 ms
*/


#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('#');
        for (char & c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if ((c == ')' && st.top() == '(') 
                    || (c == '}' && st.top() == '{') 
                    || (c == ']' && st.top() == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
        if (st.top() == '#') return true;
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.isValid("({}[()])") << endl;
    cout << solution.isValid("([)]") << endl;
    cout << solution.isValid("]") << endl;
}
