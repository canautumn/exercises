/*
228
Summary Ranges
https://leetcode.com/problems/summary-ranges/


Description:

Given a sorted integer array without duplicates, return the summary of its 
ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating 
all test cases.

(EASY) Array
Similar Problems: 163 Missing Ranges
*/

/*
SOLUTION: (Two Pointers)

Use two pointing indexes (start and end) to check ranges. 

Pitfalls:
- Mind the special case where there is only one number in the range.

[5m]
27 / 27 test cases passed.
Status: Accepted
Runtime: 0 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int start = 0, end = 0;
        while (start < nums.size()) {
            while (end < nums.size() - 1 && nums[end + 1] == nums[end] + 1) ++end;
            if (start == end) {
                result.push_back(to_string(nums[start]));
            } else {
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            start = end + 1;
            end += 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> init_array {0, 1, 2, 4, 5, 7};
    auto result = solution.summaryRanges(init_array);
    for (auto s : result) cout << s << endl;
    
    return 0;
}
