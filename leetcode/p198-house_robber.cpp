/*
198
House Robber
https://leetcode.com/problems/house-robber/


You are a professional robber planning to rob houses along a street. Each 
house has a certain amount of money stashed, the only constraint stopping you 
from robbing each of them is that adjacent houses have security system 
connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each 
house, determine the maximum amount of money you can rob tonight without 
alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. 
Also thanks to @ts for adding additional test cases.


(EASY) Dynamic Programming
*/

/*
(Dynamic Programming):

DP state transfer function:

sum[i] = MAX(sum[i-2] + num[i], sum[i-1])

Initial case: sum[0] = num[0]; sum[1] = MAX(num[0], num[1]).


Pitfalls:
- There is no need to go further on the transfer function, such as
    sum[i] = MAX(sum[i-2] + num[i], sum[i-3] + num[i-1])
It just overcomplicates the problem.

- It is easier to understand when starting from i=2, in which case you need to 
exclude a couple of edge cases (i = 0, 1, 2). See below:

    int rob(vector<int> &num) {
        if (num.size() == 0) return 0;
        if (num.size() == 1) return num[0];
        if (num.size() == 2) return max(num[0], num[1]);
        int sum_i_2 = num[0];
        int sum_i_1 = max(num[0], num[1]);
        int sum_i;
        for (int i = 2; i < num.size(); ++i) {
            sum_i = max(sum_i_2 + num[i], sum_i_1);
            sum_i_2 = sum_i_1;
            sum_i_1 = sum_i;
        }
        return sum_i;
    }
    
- Careful examination shows that the edge cases (i = 0, 1, 2) can be 
integrated into the loop by setting sum_i, sum_i_1, sum_i_2 to 0. This 
simplifies the program so that the loop starts from 0. Or you can think of 
this as sum[-1] = sum[-2] = 0 such that the general transfer equation's i 
starts from zero. See the program.


[15min]
69 / 69 test cases passed.
Status: Accepted
Runtime: 3 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        int sum_i = 0, sum_i_1 = 0, sum_i_2 = 0;
        for (int i = 0; i < num.size(); ++i) {
            sum_i = max(sum_i_2 + num[i], sum_i_1);
            sum_i_2 = sum_i_1;
            sum_i_1 = sum_i;
        }
        return sum_i;
    }
};

int main() {
    Solution solution;
    vector<int> num = {4, 3, 5, 8, 2, 7, 6};
    cout << solution.rob(num) << endl;
    
    return 0;
}
