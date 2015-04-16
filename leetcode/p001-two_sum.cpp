/*
1
Two Sum
https://leetcode.com/problems/two-sum/


Given an array of integers, find two numbers such that they add up to a 
specific target number.

The function twoSum should return indices of the two numbers such that they 
add up to the target, where index1 must be less than index2. Please note that 
your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2


(MEDIUM) Array, Hash Table
*/

/*
(Hash Map)


LEETCODE SOLUTION:

O(n^2) runtime, O(1) space – Brute force:

The brute force approach is simple. Loop through each element x and find if 
there is another value that equals to target – x. As finding another value 
requires looping through the rest of array, its runtime complexity is O(n^2).

O(n) runtime, O(n) space – Hash table:

We could reduce the runtime complexity of looking up a value to O(1) using a 
hash map that maps a value to its index.


[*]
16 / 16 test cases passed.
Status: Accepted
Runtime: 39 ms
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> target_to_sourceidx;
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i) {
            if (target_to_sourceidx.find(numbers[i]) == target_to_sourceidx.end()) {
                target_to_sourceidx[target - numbers[i]] = i;
            } else {
                result.push_back(target_to_sourceidx[numbers[i]] + 1);
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr {2, 7, 11, 15};
    for (auto i : solution.twoSum(arr, 9)) cout << i << endl;
    return 0;
}
