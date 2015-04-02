/*
119
Pascal's Triangle II
https://leetcode.com/problems/pascals-triangle-ii/


Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?


(EASY) Array
*/

/*
SOLUTION 2: (WRONG ANSWER - OVERFLOW)

For nth row and kth element (0-based):
n! / (k! * (n-k)!)

Note that to avoid floating point calculation, three factorials need to be 
calculated and then put together. Then to avoid recalculating factorials, the 
evaluation is all done around the increasing of factorials, that is we 
calculate one factorial and see where it is used. So it is a little 
mind-twisting. Finally, only left half of the array is calculated, and copy 
them to the right half.

For 'int' container, it only work for n < 13, since 13! overflows 'int' limit. 
Even changing 'int' to 'long long' (with an additional vector range 
constructor to cast long long to int) only improves the limit to 20. 
The OJ requires n<= 34.


Ex: n = 6, k = 0 to 6: [1,6,15,20,15,6,1]
(Then below rowIndex means 'n', but n is just another loop index.)
- Initialize them to be 1's.
- Leave 0 and 6 (they are 1's).
- Calculate n = 1 to 3 (4 to 5 is copied from 1 to 2 later):
- Round A, Count for k! (as well as count for the first several of n!):
  - Start from n = 2 (n = 1 doesn't need to change), update #2 to be 2! = 2, 
    then #3 to be 3! = 6;
- Round B, Count for (n-k)! and continue to count for n!:
  - Continue on n = 4 to 5, but go back on the result array, such that:
    - #(rowIndex - n + 1) *= n!
    - This is to calculate (n-k)!
    - The pitfall is that the '*= n!' happens before the current_factorial 
      increases to 4, since 3! emerges twice. Also it ends at n=1, not n=2. 
      See below:      
      ----------------------------------
      k                  0  1  2  3 ....
      initialized to     1  1  1  1 .... 
      multiplier Round A       2! 3!
      multiplier Round B    5! 4! 3! <-- 3! emerges twice in the center
      Round C dividend      6! 6! 6!
      ----------------------------------
- Round C, finished counting for n!, and use this one number divided by each 
  element of the result array. 
- Round D, copy the right half of the result array from the left half.
- Note that it passes the center when processing Round D, but it is ok.


Ex: n = 5, k = 0 to 5: [1,5,10,10,5,1]
      ----------------------------------
      k                  0  1  2 ....
      initialized to     1  1  1 .... 
      multiplier Round A       2! 
      multiplier Round B    4! 3! <-- even #, there is no center element
      Round C dividend      5! 5! 
      ----------------------------------


WRONG ANSWER (only correct for n < 21)
21 / 34 test cases passed.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<long long> result(rowIndex + 1, 1);
        long long current_factorial = 1;
        for (int n = 2; n <= rowIndex / 2; ++n) {
            current_factorial *= n;
            result[n] = current_factorial;
        }
        for (int n = rowIndex / 2 + 1; n <= rowIndex; ++n) {
            result[rowIndex - n + 1] *= current_factorial;
            current_factorial *= n;
        }
        for (int n = 1; n <= rowIndex / 2; ++n) {
            result[n] = current_factorial / result[n];
        }
        for (int n = rowIndex / 2 + 1; n < rowIndex; ++n) {
            result[n] = result[rowIndex - n];
        }
        return vector<int> (result.begin(), result.end());
    }
};

int main() {
    vector<int> result;
    Solution solution;
    result = solution.getRow(20);
    for (auto i : result) {
        cout << i << " ";
    }
    
    return 0;
}
