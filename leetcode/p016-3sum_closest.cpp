/*
16
3Sum Closest
https://leetcode.com/problems/3sum-closest/


Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers. You 
may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


(MEDIUM) Array, Two Pointers
*/

/*
SOLUTION: (Modify Two Sum problem and use sorted & two pointers)

It is a variant of Problem 15 Three Sum. The difference is that since the 
sum that is closest to the target is required, all the possible pairs should 
be checked but with the points below in mind:

- If an exact match is found (sum == target, or difference is zero), the loop 
can be terminated since it must be the best result you can get.
- Sorting and two-pointer strategy still critical to the performance. Since we 
are searching for the closest pair, given the first number fixed, we move one 
of the two pointers each step based on whether the sum is larger or smaller. 
This is the key of using sorted array and two pointers for Two Sum and Three 
Sum problems.
- In addition, we compare the absolute value of the difference but store the 
original value of the difference. At the end, we need to use the original value 
of the difference to restore the sum.

There is no need to check duplicated elements since only the closest one case 
is needed. Adding duplicate check in two level as in problem 15 only have 
minor performance improvement. Below is a simpler version without duplicate 
check that runs 29ms vs 24ms that has the duplicate check.


    int threeSumClosest(vector<int>& nums, int target) {
        int result = numeric_limits<int>::max();
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i != nums.end() - 2; ++i) {            
            auto left = i + 1, right = nums.end() - 1;
            while (left < right) {
                int diff = *left + *right + *i - target;
                if (abs(diff) < abs(result)) result = diff;
                if (*left + *right + *i == target) 
                    return target;
                else if (*left + *right + *i < target)
                    left++;
                else
                    right--;
            }
        }
        return result + target;

    }

The time complexity is O(n^2) like the Three Sum problem. 

Arrays with less than 3 elements are not checked as indicated in the problem 
description.


Another variant is using array subscription. The idea is the same but it seems 
that it is faster, and the code looks much simpler.

    int threeSumClosest(vector<int> &nums, int target) {        
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - result) > abs(target - sum)) {
                    result = sum;
                    if (result == target) return result;
                }
                (sum > target) ? k-- : j++;
            }
        }
        return result;
    }

The above implementation: Runtime: 15 ms


[30m]
120 / 120 test cases passed.
Status: Accepted
Runtime: 24 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = numeric_limits<int>::max();
        sort(nums.begin(), nums.end());
        int lastnum;
        for (auto i = nums.begin(); i != nums.end() - 2; ++i) {
            if (i != nums.begin() && *i == lastnum) continue;
            auto left = i + 1, right = nums.end() - 1;
            while (left < right) {
                int diff = *left + *right + *i - target;
                if (abs(diff) < abs(result)) result = diff;
                if (*left + *right + *i == target) {
                    return target;
                } else if (*left + *right + *i < target) {
                    auto current_left = left;
                    while (left < right && *current_left == *left) left++;
                } else {
                    auto current_right = right;
                    while (left < right && *current_right == *right) right--;
                }
                    
            }
            lastnum = *i;
        }
        return result + target;
    }
};

int main() {
    Solution solution;
    // vector<int> arr {-1, 2, 1, -4};
    vector<int> arr {0, 2, 1, -3};
    // vector<int> arr {0, 0, 0};
    cout << solution.threeSumClosest(arr, 1) << endl;
    return 0;
}
