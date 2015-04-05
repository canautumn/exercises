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
SOLUTION 1 (Iteration):

Observe when the number of zeros increases when increasing n:

n = 5 -> 1; n = 10 -> 2; n = 15 -> 3; n = 20 -> 4; n = 25 -> 6;

When n is increased from 24 to 25, the number of zeros increased by 2. Because 
25 is 5^2, the number of factor 5 is increased by 2. Further more, we can 
deduce that when n is increased from 124 to 125, the number of zeros is 
increased by 3, because 125 is 5^3. 

This is because for any n > 5, there is always a factor of 2 (from any even 
number) to be paired with a 5 to get 10. Thus the number of zeros are purely 
depending on the number of factor 5.

It can be verified in Wolfram Alpha.

The first solution is that we can find how many 5's, how many 25's, how many 
125's ... how many 5^k (5^k <= n) are there in 1 to n, and add them together. 
This will be a logarithmic algorithm.

Pitfalls:

The first attempt is as follows:

    int trailingZeroes(int n) {
        int result = 0, divisor = 5;
        while (int count = n / divisor) {
            result += count;
            divisor *= 5;
        }
        return result;

This runs OK except TLE on the case 2147483647. This is because the last 
divisor it tries to find overflows and turns to a negative number, thus the 
loop never ends. Change divisor from int to long avoids the problem and passed 
the OJ. However, there are more elegant way to avoid the problem. See Solution 
1 Optimization 2.

502 / 502 test cases passed.
Status: Accepted
Runtime: 10 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        long divisor = 5;
        while (int count = n / divisor) {
            result += count;
            divisor *= 5;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.trailingZeroes(2147483647) << endl;
    
    return 0;
}
