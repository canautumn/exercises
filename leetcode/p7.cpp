/*
7
Reverse Integer
https://oj.leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.

*/

/*
"if (result + digit / 10.0 > numeric_limits<int>::max() / 10.0)"
Using this condition to check the overflow before it overflows. Float is used to check all the digits.
However, since the limit is 2147483647, and 7 > 2, the check of next digit (as the first decimal) may not necessary.

2015-2-27
1032 / 1032 test cases passed.
Status: Accepted
Runtime: 14 ms
*/

/* SOLUTION:
To check for overflow/underflow, we could check if ret > 214748364 or ret < –214748364 before multiplying by 10. On the other hand, we do not need to check if ret == 214748364, why?
*/


#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0) {
            negative = true;
            x = - x;
        }
        int result = 0;
        while (x > 0) {
            short digit = x % 10;
            x = x / 10;
            if (result + digit / 10.0 > numeric_limits<int>::max() / 10.0) {
                return 0;
            }
            result = result * 10 + digit;
            
        }
        return negative ? - result : result;
    }
};

int main() {
    Solution solution;
    cout << solution.reverse(1563847412) << endl;
    // cout << numeric_limits<int>::max() << endl;
}
