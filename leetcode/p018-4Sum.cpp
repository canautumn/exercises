/*
18
4Sum
https://leetcode.com/problems/4sum/


Description:

Given an array S of n integers, are there elements a, b, c, and d in S such 
that a + b + c + d = target? Find all unique quadruplets in the array which 
gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
(ie, a ≤ b ≤ c ≤ d)

The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

(EASY) Array, Hash Table, Two Pointers
Similar Problems: 1 (M) Two Sum, 15 (M) 3Sum
*/

/*
SOLUTION 1: (Extend 3Sum and Two Sum)

Just like 3Sum, add another level of loop of calls to 3Sum to extend the 3Sum 
problem to 4Sum. This solution is however not optimal. See VARIANT 1 and 
SOLUTION 2.

[20m]
282 / 282 test cases passed.
Status: Accepted
Runtime: 172 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        if (nums.size() < 4) return results;
        sort(nums.begin(), nums.end());
        int last_num;
        for (auto i = nums.begin(); i != nums.end() - 3; ++i) {
            if (i != nums.begin() && *i == last_num) continue;
            last_num = *i;
            auto triplets = threeSum(vector<int> (i + 1, nums.end()), target - (*i));
            for (size_t k = 0; k < triplets.size() / 3; ++k) {
                results.push_back(vector<int> {*i, triplets[k * 3], triplets[k * 3 + 1], triplets[k * 3 + 2]});
            }
        }
        return results;
    }
private:
    vector<int> threeSum(const vector<int> &nums, int target) {
        vector<int> results;
        int last_num;
        for (auto i = nums.begin(); i != nums.end() - 2; ++i) {
            if (i != nums.begin() && *i == last_num) continue;
            last_num = *i;
            auto pairs = twoSum(vector<int> (i + 1, nums.end()), target - (*i));
            for (size_t k = 0; k < pairs.size() / 2; ++k) {
                results.push_back(*i);
                results.push_back(pairs[k * 2]);
                results.push_back(pairs[k * 2 + 1]);
            }
        }
        return results;
    }
    vector<int> twoSum(const vector<int> &numbers, int target) {
        vector<int> result;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
                if (numbers[left] + numbers[right] == target) {
                result.push_back(numbers[left]);
                result.push_back(numbers[right]);
                int current_left = numbers[left];
                while (left < right && current_left == numbers[left]) left++;
                int current_right = numbers[right];
                while (left < right && current_right == numbers[right]) right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr {1, 0, -1, 0, -2, 2};
    for (auto s : solution.fourSum(arr, 0)) {
        for (auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
