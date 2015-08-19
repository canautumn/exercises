/*
263
Ugly Number
https://leetcode.com/problems/ugly-number/


Description:

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For 
example, 6, 8 are ugly while 14 is not ugly since it includes another prime 
factor 7.

Note that 1 is typically treated as an ugly number.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all 
test cases.

(EASY) Math
Similar Problems: 202 Happy Number, 204 Count Primes, 264 Ugly Number II
*/

/*
SOLUTION: 

Given a number 'num', repeatedly divide it by 2, 3, 5 until not divisible, the 
remainder is 1 if it is ugly. Otherwise it is not.

The test set also requires checking for 0 to prevent infinite loop.

[10m]
1012 / 1012 test cases passed.
Status: Accepted
Runtime: 8 ms
*/


#include <iostream>
    
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        while (!(num % 2)) num /= 2;
        while (!(num % 3)) num /= 3;
        while (!(num % 5)) num /= 5;
        return (num == 1);
    }
};

int main() {
    Solution solution;
    cout << solution.isUgly(18) << endl;
     
    return 0;
}
