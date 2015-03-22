/*
70
Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you 
climb to the top?

(EASY) Dynamic Programming
*/

/*
S(n) = S(n-1) + S(n-2)
S(0) = 1
S(1) = 1

(It's Fibonacci Sequence. Use a loop (Dynamic Programming) instead of 
recursion or memoization.)

45 / 45 test cases passed.
Status: Accepted
Runtime: 3 ms
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        int sn_1 = 1, sn_2 = 1, sn = 0;
        for (int i = 2; i <= n; ++i) {
            sn = sn_1 + sn_2;
            sn_2 = sn_1;
            sn_1 = sn;
        }
        return sn;
    }
};

int main() {
    Solution solution;
    cout << solution.climbStairs(7) << endl;
}
