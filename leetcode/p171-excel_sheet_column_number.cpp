/*
171
Excel Sheet Column Number
https://leetcode.com/problems/excel-sheet-column-number/


Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding 
column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


(EASY) Math
*/

/*
It is the reverse problem of Problem 168 Excel Sheet Column Title.

No time data.
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (auto c : s) {
            result *= 26;
            result += c - 'A' + 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.titleToNumber("AB") << endl;
    
    return 0;
}
