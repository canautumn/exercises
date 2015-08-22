/*
22
Generate Parentheses
https://leetcode.com/problems/generate-parentheses/


Description:

Given n pairs of parentheses, write a function to generate all combinations of 
well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

(EASY) Backtracking, String
Similar Problems: 17 (M) Letter Combinations of a Phone Number, 
20 (E) Valid Parentheses
*/

/*
SOLUTION: (Backtracking with recursion)

This is a very typical backtracking problem. Using recursion is quite intuitive. 
For recursion, use a string variable to store current strings, and left, right 
parenthesis count variable to keep the invariants -- left <= n, left >= right.

[5m]
8 / 8 test cases passed.
Status: Accepted
Runtime: 0 ms
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        backtrack(n, 0, 0, "", results);
        return results;
    }
private:
    void backtrack(int n, int left, int right, string current, vector<string> &results) {
        if (left == n) {
            current += string(left - right, ')');
            results.push_back(current);
            return;
        }
        backtrack(n, left + 1, right, current + "(", results);
        if (left > right) backtrack(n, left, right + 1, current + ")", results);
    }
};

int main() {
    Solution solution;
    for (auto s : solution.generateParenthesis(3)) cout << s << endl;
    
    return 0;
}
