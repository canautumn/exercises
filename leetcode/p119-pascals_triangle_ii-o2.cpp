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
SOLUTION 1 OPTIMIZATION 2: 
Using the same method as Solution 1, but consider that why we needed the 
temporary overwrite backup. Because each element requires the previous value 
of that element and the one before this element, and the latter one will get 
overwrote by the previous element of this iteration. But if we iterate back 
from the end of the array, the problem is gone automatically, since the two 
old values of the elements are both not updated in the current iteration.

Note that the answer only accepts int vector, which limits the input to be 
n < 34 to have a valid result.

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
        for(int i = 1; i <= rowIndex - 1; i++)
            for(int j = i; j > 0; j--)
                result[j] = result[j] + result[j-1];
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
