/*
12
Integer to Roman
https://leetcode.com/problems/integer-to-roman/

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

(MEDIUM) Math String
*/

/*
Process thousands (special case) first. Then process hundreds, using string 
literals such as "M", "C", "D". Then the rule can be seen. Combine the 
processing of hundreds, tens, ones together in a loop, and use a symbol table 
and a pointer pointing to corresponding symbols.


3999 / 3999 test cases passed.
Status: Accepted
Runtime: 46 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string result(num / 1000, 'M');
        num = num % 1000;
        int s_i = 6;        
        for (int i = 100; i >= 1; i /= 10) {
            int digit = num / i;
            if (digit > 0 && digit < 4) {
                result.append(string(digit, symbols[s_i - 2]));
            } else if (digit == 4) {
                result.append(string(1, symbols[s_i - 2]));
                result.append(string(1, symbols[s_i - 1]));
            } else if (digit > 4 && digit < 9) {
                result.append(string(1, symbols[s_i - 1]));
                result.append(string(digit - 5, symbols[s_i - 2]));
            } else if (digit == 9) {
                result.append(string(1, symbols[s_i - 2]));
                result.append(string(1, symbols[s_i]));
            }
            s_i -= 2;
            num %= i;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.intToRoman(1954) << endl;
    cout << solution.intToRoman(1990) << endl;
    cout << solution.intToRoman(2014) << endl;
}