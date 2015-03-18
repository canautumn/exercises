/*
14
Write a function to find the longest common prefix string amongst an array of strings.
https://oj.leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

(EASY) String
*/

/*

Corner cases:
- No element in the vector.
- Empty string at beginning or other positions.
- String to compare is shorter or longer than the current common prefix.

20m
117 / 117 test cases passed.
Status: Accepted
Runtime: 9 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string result = strs[0];
        int prefix_len = result.size();
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].size() == 0) {
                return "";
            }
            for (int j = 0; j < strs[i].size(); ++j) {
                if (j == prefix_len) break;
                if (strs[i][j] != result[j]) {
                    prefix_len = j;
                    break;
                }
            }
            prefix_len = prefix_len <= strs[i].size() ? prefix_len : strs[i].size();
        }
        result.resize(prefix_len);
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input1({"mrtantaaczxga", "mrtantaaczdgggare", "mrtantmma12h"});
    vector<string> input2({"mrtantaaczxga", "mrtantaaczdgggare", ""});
    vector<string> input3({"", "mrtantaaczxga", "mrtantaaczdgggare"});
    vector<string> input4({"aa", "a"});
    cout << solution.longestCommonPrefix(input1) << endl;
    cout << solution.longestCommonPrefix(input2) << endl;
    cout << solution.longestCommonPrefix(input3) << endl;
    cout << solution.longestCommonPrefix(input4) << endl;
}