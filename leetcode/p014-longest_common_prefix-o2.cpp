/*
14
Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
https://oj.leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

(EASY) String
*/

/*

Another solution: sort the string and only compare the first and the last string.

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int i, j, n = strs.size();
        if (n == 0) return "";
        sort(strs.begin() ,strs.begin() + n);
        for (j = 0; j < strs[0].size() && j < strs[n - 1].size() && strs[0][j] == strs[n - 1][j]; j++);
        return strs[0].substr(0, j);
    }
};

int main() {
    Solution solution;
    vector<string> input1({"mrtantaaczxga", "mrtantaaczdgggare", "mrtantmma12h"});
    vector<string> input2({"mrtantaaczxga", "mrtantaaczdgggare", ""});
    vector<string> input3({"z", "bb", "zzz"});
    vector<string> input4({"aa", "a"});
    cout << solution.longestCommonPrefix(input1) << endl;
    cout << solution.longestCommonPrefix(input2) << endl;
    cout << solution.longestCommonPrefix(input3) << endl;
    cout << solution.longestCommonPrefix(input4) << endl;
}