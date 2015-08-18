/*
217
Contains Duplicate
https://leetcode.com/problems/contains-duplicate/


Description:

Given an array of integers, find if the array contains any duplicates. Your 
function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

(EASY) Array, Hash Table
Similar Problems: 219 Contains Duplicate II, 220 Contains Duplicate III
*/

/*
SOLUTION: (Hash Set using unordered_set<int>)

[2m]
16 / 16 test cases passed.
Status: Accepted
Runtime: 48 ms
*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> emerged;
        for (int i = 0; i < nums.size(); ++i) {
            if (emerged.find(nums[i]) != emerged.end()) return true;
            emerged.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> init_array {1, 2, 6, 3, 4, 5, 6};
    
    cout << solution.containsDuplicate(init_array);
 
    return 0;
}
