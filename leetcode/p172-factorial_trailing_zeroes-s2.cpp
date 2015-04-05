/*
172
Factorial Trailing Zeroes
https://leetcode.com/problems/factorial-trailing-zeroes/


Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


(EASY) Math
*/

/*
SOLUTION 2 (Recursion, from n to 0):

It is the recursion version of Solution 1 Optimization 2.

Note that the running time of these three programs cannot be compared since 
they have very small differences. For this kind of small difference, run it 
again in the OJ you get different time.

502 / 502 test cases passed.
Status: Accepted
Runtime: 9 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;
        return n / 5 + trailingZeroes(n / 5);
    }
};

int main() {
    Solution solution;
    cout << solution.trailingZeroes(2147483647) << endl;
    
    return 0;
}
