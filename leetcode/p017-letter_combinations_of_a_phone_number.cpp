/*
17
Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/


Description:

Given a digit string, return all possible letter combinations that the number 
could represent.

A mapping of digit to letters (just like on the telephone buttons) is given 
below.

(Figure)

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in 
any order you want.

(EASY) Backtracking, String
Similar Problems: 22 Generate Parentheses, 39 Combination Sum
*/

/*
SOLUTION: (Backtracking using recursion)

Use recursion for backtracking the numbers one by one. For each level, track 
all the possible numbers for this number recursively. Also, pass the current 
combinations of letters to the next level. When all the numbers are reached, 
push the result array.

[20m]
25 / 25 test cases passed.
Status: Accepted
Runtime: 0 ms
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.size() == 0) return results;
        const vector<string> map {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0, map, "", results);
        return results;
    }
private:
    void backtrack(const string& digits, int i, const vector<string>& map, const string current, vector<string>& results) {
        if (i == digits.size() - 1) {
            string letters = map[digits[i] - '2'];
            for (int k = 0; k < letters.size(); ++k) {
                results.push_back(current + letters[k]);
            }
            return;
        }
        string letters = map[digits[i] - '2'];
        for (int k = 0; k < letters.size(); ++k) {
            backtrack(digits, i + 1, map, current + letters[k], results);
        }
    }
};

int main() {
    Solution solution;
    for (auto s : solution.letterCombinations("23")) cout << s << endl;
     
    return 0;
}
