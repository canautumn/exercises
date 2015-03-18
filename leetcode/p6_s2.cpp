/*
6
ZigZag Conversion
https://oj.leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/* ---- 

For row=4, 
    P     I     N
    A   L S   I G
    Y A   H R
    P     I
    

Time:
36ms - 1158 cases

---- */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        if (s.size() <= nRows) return s;
        
        string result(s.size(), ' ');
        
        
        int num_elem_fullgroup = nRows * 2 - 2;
        int num_fullgroup = s.size() / num_elem_fullgroup;
        int residue_fullgroup = s.size() % num_elem_fullgroup;

        int i = 0, step = 1;
        vector<int> cumulative_idx_offset_within_group(nRows), cumulative_idx_offset_by_residue(nRows);
        for (int j = 0; j < num_elem_fullgroup; ++j) {
            if (i == nRows - 1) step = -1;
            cumulative_idx_offset_within_group[i]++;
            if (j < residue_fullgroup) cumulative_idx_offset_by_residue[i]++;
            i += step;
        }
        for (int i = 1; i < nRows; ++i) {
            cumulative_idx_offset_by_residue[i] += cumulative_idx_offset_by_residue[i - 1];
            cumulative_idx_offset_within_group[i] += cumulative_idx_offset_within_group[i - 1];
        }
        // for (int j = 0; j < nRows; ++j) cout << cumulative_idx_offset_within_group[j] << endl;
        // for (int j = 0; j < nRows; ++j) cout << cumulative_idx_offset_by_residue[j] << endl;
        
        
        for (int s_idx = 0; s_idx < s.size(); ++s_idx) {
            int idx_of_group = s_idx / num_elem_fullgroup;
            int idx_within_group = s_idx % num_elem_fullgroup;
            int row = idx_within_group <= num_elem_fullgroup / 2 ? idx_within_group : num_elem_fullgroup - idx_within_group;
            // cout << row << endl;
            int result_idx;
            if (row == 0) {
                result_idx = idx_of_group;
                // cout << result_idx << endl;
            } else {
                result_idx = cumulative_idx_offset_within_group[row - 1] * num_fullgroup
                            + cumulative_idx_offset_by_residue[row - 1]
                            + (row == nRows - 1 ? 1 : 2) * idx_of_group
                            + (idx_within_group <= num_elem_fullgroup / 2 ? 0 : 1);
            }            
            // cout << s_idx << ":" << result_idx << endl;
            result[result_idx] = s[s_idx];
        }

        
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING---------", 5) << endl;
    // cout << solution.convert("PAYPALISHIRING", 3) << endl;
    // cout << solution.convert("ABCD", 3) << endl;
    return 0;
}
