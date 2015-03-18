/*
13
Roman to Integer 
https://oj.leetcode.com/problems/roman-to-integer/

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

(EASY) Math String
*/

/*
From Wikipedia:
the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX) respectively
X can be placed before L and C to make 40 (XL) and 90 (XC) respectively
C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern

13m.

- A simpler method is to use a map or a function to do letter->int, and check if the next digit is 
larger than the current one, and if so, subtract it instead of adding it.

3999 / 3999 test cases passed.
Status: Accepted
Runtime: 60 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == 'M') {
                result += 1000;
            }
            if (s[i] == 'D') {
                result += 500;
            }
            if (s[i] == 'C') {
                if (i + 1 < s.size()) {
                    if (s[i+1] == 'D') {
                        result += 400;
                        i += 2;
                        continue;
                    }
                    if (s[i+1] == 'M') {
                        result += 900;
                        i += 2;
                        continue;
                    }
                }
                result += 100;
            }
            if (s[i] == 'L') {
                result += 50;
            }
            if (s[i] == 'X') {
                if (i + 1 < s.size()) {
                    if (s[i+1] == 'L') {
                        result += 40;
                        i += 2;
                        continue;
                    }
                    if (s[i+1] == 'C') {
                        result += 90;
                        i += 2;
                        continue;
                    }
                }
                result += 10;
            }
            if (s[i] == 'V') {
                result += 5;
            }
            if (s[i] == 'I') {
                if (i + 1 < s.size()) {
                    if (s[i+1] == 'V') {
                        result += 4;
                        i += 2;
                        continue;
                    }
                    if (s[i+1] == 'X') {
                        result += 9;
                        i += 2;
                        continue;
                    }
                }
                result += 1;
            }
            i++;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("MCMIV") << endl;
}