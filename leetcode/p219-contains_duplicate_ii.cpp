/*
219
Contains Duplicate II
https://leetcode.com/problems/contains-duplicate-ii/


Description:

Given an array of integers and an integer k, find out whether there are two 
distinct indices i and j in the array such that nums[i] = nums[j] and the 
difference between i and j is at most k.

(EASY) Array, Hash Table
Similar Problems: 217 Contains Duplicate, 220 Contains Duplicate III
*/

/*
SOLUTION: (Hash Map using unordered_multimap<int, int>)

Tips:
- The distance calculation requires recording indices of each emerged number. 
So the multi-map is needed.
- Get familiar with C++11's multi-map usage.
- (The actual running speed using STL is not bad among all the testers.)

[25m]
19 / 19 test cases passed.
Status: Accepted
Runtime: 36 ms
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_multimap<int, int> emerged;
        for (int i = 0; i < nums.size(); ++i) {
            auto range = emerged.equal_range(nums[i]);
            bool is_dup = false;
            for_each(
                range.first, 
                range.second, 
                [k, i, &is_dup] (unordered_multimap<int, int>::value_type& x) {
                    if (i - x.second <= k) {
                        is_dup = true;
                        return;
                    }
                });
            if (is_dup) return true;
            emerged.insert(make_pair(nums[i], i));
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> init_array {1, 2, 6, 3, 4, 5, 6};
    
    cout << solution.containsNearbyDuplicate(init_array, 4);
 
    return 0;
}
