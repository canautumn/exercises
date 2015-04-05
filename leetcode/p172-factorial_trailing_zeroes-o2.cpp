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
SOLUTION 1 OPTIMIZATION 2 (Iteration, from n to 0):

From Solution 1 discussion we know that for any n > 5, there is always a 
factor of 2 (from any even number) to be paired with a 5 to get 10. Thus the 
number of zeros are purely depending on the number of factor 5.

In Solution 1, we find how many 5's, how many 25's, how many 125's ... how 
many 5^k (5^k <= n) are there in 1 to n, and add them together. But we used a 
method not so good that we increase the divisor 5^k, and use the same n as the 
dividend. This is ok and have the same time complexity as the method below but 
the divisor could overflow when approaching n if no additional care is taken. 

In this method, we use the same idea but every time we use the same divisor 5, 
but different dividend: n, n/5, n/5^2, ..., to achieve the same goal. 

A top-down method is preferred in this kind of problem, using the idea that a 
large number problem is always solved step by step and turning it into small 
problems by either iteration or recursion. 

Solution 2 is the recursion version of this same method.

502 / 502 test cases passed.
Status: Accepted
Runtime: 8 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n) {
            result += n /= 5;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.trailingZeroes(2147483647) << endl;
    
    return 0;
}
