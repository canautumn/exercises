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
SOLUTION 2: (Passed, limit n<34, direct calculation)

For nth row and kth element (0-based):
n! / (k! * (n-k)!)

To use this equation and maximize the overflow limit, we have to minimize the 
intermediate numbers:
- Note that if we only calculate the first half, (and copy the result using 
symmetry) large number (n-k)! can be fully canceled by part of n!. We count 
this part as multiplier A ([mtp_A] below). The other part is multiplier B.
- Also, we need to avoid intermediate overflow, by dividing the number as 
early as possible. And it won't lead to floating result since the dividend 
is always dividable.

To pass the OJ, we only need to change the current_multiplier to be long to 
accommodate intermediate large number. Otherwise it will overflow when 
n > 29 (not that bad though).

Ex: n = 6, k = 0 to 6: [1,6,15,20,15,6,1]
      ----------------------------------
      k                  0  1  2   3 ....
      k!        [mtp_B]        2!  3!
      (n-k)!                5! 4!  3! <-- 3! emerges twice in the center
      n!                    6! 6!  6!
      n!/(n-k)! [mtp_A]     6  6*5 6*5*4
      ----------------------------------


Ex: n = 5, k = 0 to 5: [1,5,10,10,5,1]
      ----------------------------------
      k                  0  1  2   ....
      k!        [mtp_B]        2!
      (n-k)!                4! 3! <-- even #, there is no center element
      n!                    5! 5!  
      n!/(n-k)! [mtp_A]     5  5*4 
      ----------------------------------



Like solution 1, it will work for n < 34 because of the limit of the result 
type. It is faster than solution 1 since there is only one pass.

34 / 34 test cases passed.
Status: Accepted
Runtime: 2 ms
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        long current_multiplier = 1;
        for (int n = 1; n <= rowIndex / 2; ++n) {
            current_multiplier *= (rowIndex - n + 1);
            current_multiplier /= n;
            result[n] = current_multiplier;
        }
        for (int n = rowIndex / 2 + 1; n < rowIndex; ++n) {
            result[n] = result[rowIndex - n];
        }
        return result;
    }
};

int main() {
    vector<int> result;
    Solution solution;
    result = solution.getRow(33);
    for (auto i : result) {
        cout << i << " ";
    }
    
    return 0;
}
