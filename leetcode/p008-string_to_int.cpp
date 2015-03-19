/*
8
String to Integer (atoi)
https://oj.leetcode.com/problems/string-to-integer-atoi/

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

/*
Try C++ built-in atoi (note that it accepts char* though) especially corner cases.

- The loop deals with all legal possibilities first, and break if any illegal condition is met.
- Remember to deal with the optional '+'.
- Remember to deal with the overflow (negative or positive ones).

1045 / 1045 test cases passed.
Status: Accepted
Runtime: 16 ms
*/

/* SOLUTION
To deal with overflow, inspect the current number before multiplication. If the current number is greater than 214748364, we know it is going to overflow. On the other hand, if the current number is equal to 214748364, we know that it will overflow only when the current digit is greater than or equal to 8.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        int result = 0;
        bool has_began = false;
        bool negative = false;
        for (char & c : str) {
            // cout << c << endl;
            if (isspace(c) && !has_began) continue;
            if (c == '-' && !has_began) {
                negative = true;
                has_began = true;
                // cout << "neg";
                continue;
            }
            if (c == '+' && !has_began) {
                has_began = true;
                continue;
            }            
            if (c >= '0' && c <= '9') {
                // cout << c ;
                has_began = true;
                if (!negative && result + (c - 48) / 10.0 > numeric_limits<int>::max() / 10.0) {
                    return numeric_limits<int>::max();
                }
                if (negative && -result - (c - 48) / 10.0 < numeric_limits<int>::min() / 10.0) {
                    return numeric_limits<int>::min();
                }
                result = result * 10 + (c - 48);
                // cout << result << endl;
                continue;
            }
            break;
        }
        return negative ? - result : result;
    }
};

int main() {
    Solution solution;
    cout << solution.atoi("\t -345c2 114") << endl;
    cout << solution.atoi("3452 -114") << endl;
    cout << solution.atoi("+1") << endl;
    cout << solution.atoi("2147483648") << endl;
    cout << solution.atoi("2147483646") << endl;
    cout << solution.atoi("-2147483648") << endl;
    cout << solution.atoi("-2147483649") << endl;
    cout << solution.atoi("-1") << endl;
}