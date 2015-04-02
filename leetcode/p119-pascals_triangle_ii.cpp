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
SOLUTION 1: (Successive equation, in place updating)
The same calculation as the calculation of full triangle can now be done in 
place with an array. We will calculate row by row and update each row in place 
one element by one element. Just need to notice we need a backup of the 'old' 
version of the previous element to calculate the current element.

Notice that the trivial case when rowIndex = 0 and 1 are automatically 
included.

Note that the answer only accepts int vector, which limits the input to be 
n < 34 to have a valid result.

34 / 34 test cases passed.
Status: Accepted
Runtime: 3 ms
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            int overwrite_backup = 1;
            for (int j = 1; j < i; ++j) {
                int overwrite_swap = result[j];
                result[j] = overwrite_backup + result[j];
                overwrite_backup = overwrite_swap;
            }
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
