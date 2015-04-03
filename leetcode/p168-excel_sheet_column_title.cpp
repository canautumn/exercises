/*
168
Excel Sheet Column Title
https://leetcode.com/problems/excel-sheet-column-title/


Given a positive integer, return its corresponding column title as appear in 
an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 


Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.


(EASY) Math
*/

/*
It is basically base conversion (but not truly is), with some pitfalls. 

In this 'base 26'-like system, 'A' sometimes like zero, and sometimes like 1. 
When we consider 'A' as 0, it is ok after let n-- for the first time. Then in 
the second digit, 'A' is like 1. We must again n-- otherwise 'Z' will be 
followed by 'BA'. So we can just n-- for each digit. 

See the comparison between the Excel title system and true base 26 system. 

        Excel title system[num of nums]        True base 26 system[num of nums]
        ------------------                     -------------------
1 digs: 0-25 (A - Z)               [26]        0-25        [26]
2 digs: 0x-25x (x is 0-25) (AA-ZZ) [26*26]     1x-25x      [25*26]
3 digs: 0xx - 25xx (AAA-ZZZ)       [26*26*26]  1xx - 25xx  [25*26*26]
...

Here you can see that for each digit 'Excel' system has one more number than 
the base 26 system. Or consider this equivalent loop:

        while (n) {
            result.append(1, (n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }

The first (n - 1) is for the Decimal number 1 is actually 0 for conversion. 
The second (n - 1) is for the additional number of the next digit.

Tips:
- Using string's append() and then reverse it is slightly faster than insert() 
at the beginning of the string repeatedly.

18 / 18 test cases passed.
Status: Accepted
Runtime: 1 ms
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            n--;
            result.append(1, n % 26 + 'A');
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    for (int i = 1; i < 999; ++i) {
        cout << solution.convertToTitle(i) << endl;
    }
    
    return 0;
}
