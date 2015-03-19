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
    
Improvement on s3:
    Change some parameter precalculated into vectors to calculate on site.
    Saving 2 more small loops but the performance doesn't get much better.


Time:
29ms - 1158 cases

---- */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        if (s.size() <= nRows) return s;
        
        string result;
        result.resize(s.size());
        // This is faster than "string result(s.size(), ' ');"
        
        int num_elem_fullgroup = nRows * 2 - 2;
        int num_fullgroup = s.size() / num_elem_fullgroup;
        int residue_fullgroup = s.size() % num_elem_fullgroup;
/*
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
            // cout << cumulative_idx_offset_within_group[i] << endl;
            // cout << (i == nRows - 1 ? i * 2 : 1 + i * 2) << endl;
            int row = i + 1;
            // int current_cumulative_idx_offset_within_group = cumulative_idx_offset_within_group[i];
            int current_cumulative_idx_offset_by_residue;
            if (residue_fullgroup <= num_elem_fullgroup / 2 || num_elem_fullgroup - (row - 1) >= residue_fullgroup) {
                cout << "aa";
                current_cumulative_idx_offset_by_residue = ((row - 1) + 1 < residue_fullgroup) ? (row - 1) + 1 : residue_fullgroup;
            } else {
                current_cumulative_idx_offset_by_residue = ((row - 1) + 1) + residue_fullgroup - (num_elem_fullgroup / 2 + 1) - (nRows - 2 - (row - 1));
            }   
            cout << current_cumulative_idx_offset_by_residue << "-";
            cout << cumulative_idx_offset_by_residue[i] << endl;
        }
        // for (int j = 0; j < nRows; ++j) cout << cumulative_idx_offset_within_group[j] << endl;
*/
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
                // we need to get the cumulative offset of (row - 1), which is not going to be the last row. No need to check that.
                int current_cumulative_idx_offset_within_group = (1 + (row - 1) * 2);
                int current_cumulative_idx_offset_by_residue;
                if (residue_fullgroup <= num_elem_fullgroup / 2 || num_elem_fullgroup - (row - 1) >= residue_fullgroup) {
                    current_cumulative_idx_offset_by_residue = ((row - 1) + 1 < residue_fullgroup) ? (row - 1) + 1 : residue_fullgroup;
                } else {
                    current_cumulative_idx_offset_by_residue = ((row - 1) + 1) + residue_fullgroup - (num_elem_fullgroup / 2 + 1) - (nRows - 2 - (row - 1));
                }
                result_idx = current_cumulative_idx_offset_within_group * num_fullgroup // cumulative_idx_offset_within_group[row-1]
                            + current_cumulative_idx_offset_by_residue // cumulative_idx_offset_by_residue[row - 1]
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
    // cout << solution.convert("PAYPALISHIRING---------", 10) << endl;
    // cout << solution.convert("PAYPALISHIRING", 3) << endl;
    cout << solution.convert("AB", 1) << endl;
    return 0;
}
// PH-ASI--YIR---PLIG--AN-