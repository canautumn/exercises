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
    
Corner cases: nRows = 1, the algorithm will run over the index limit of row
(1 or -1). We can check if the row is out of limit, but more concise way is 
to just return s if nRows == 1, since all other cases the row will not be 
out of limit without hitting the edge case (nRows-1, or 0) first.

String processing performance: += (with reserve) is better than direct 
concatenation or ostringstream. But if we reserve for each of the rows_string
element, that is going to be worse.

REF: 
http://stackoverflow.com/questions/18892281/most-optimized-way-of-concatenation-in-strings

Time:
30ms - 1158 cases

---- */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string result;
        result.reserve(s.size());
        vector<string> rows_string(nRows);
        int row = 0;
        int step = 1;
        for (int i = 0; i < s.size(); ++i) {
            rows_string[row] += s[i];
            row += step;
            if (row == nRows - 1) step = -1;
            if (row == 0) step = 1;
        }
        for (int i = 0; i < nRows; ++i) {
            result += rows_string[i];
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    cout << solution.convert("AB", 2) << endl;
    
    return 0;
}
