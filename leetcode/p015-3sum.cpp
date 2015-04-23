/*
15
3Sum
https://leetcode.com/problems/3sum/


Given an array S of n integers, are there elements a, b, c in S such that 
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


(MEDIUM) Array, Two Pointers
*/

/*
SOLUTION: (Modify Two Sum problem and use sorted & two pointers)

This is an extension to Problem 1 (Two Sum). In Two Sum, there are two 
solutions, one is using hash table and another is to sort the array and using 
two pointers. The hash table has smaller order of complexity but may not beat 
the sorting solution in real performance. 

Two Sum an served as a subroutine in the Three Sum problem. Sort the array and 
iteratively take one element of the array and make the opposite number as the 
target as in the Two Sum problem, and the rest of the array (starting from the 
next element of the target until the end) as the search array (and note that 
it is already sorted) and pass them into a Two Sum problem function. The Two 
Sum function needs to be modified that it returns the numbers, not indexes; 
also it needs to search multiple instances of the pairs. 

We also note that Three Sum problem requires the results are unique. It costs 
a lot to using a hash set to implement it. Actually, we can avoid the repeated 
result instances in the procedure because the array is sorted. We make use of 
the fact that the repeated instances are all because of the repeated numbers 
and they are together in a sorted array. 

Be careful that there are two kinds of repeats that we need to avoid them both. 
First kind is the repeated first number (or target as in the Two Sum function), 
which can be excluded before calling Two Sum subroutine by checking if it is 
the same as the last element. The second level is the repeats of the last two 
numbers in the results. This can be excluded in the Two Sum subroutine when 
moving the two pointers towards the center, which should skip the repeated 
elements. 


[*]
311 / 311 test cases passed.
Status: Accepted
Runtime: 68 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if (num.size() < 3) return result;
        sort(num.begin(), num.end());
        int lastnum;
        for (auto i = num.begin(); i != num.end() - 2; ++i) {
            if (i != num.begin() && *i == lastnum) continue;
            auto pair = twoSum(vector<int> (i + 1, num.end()), -(*i));
            for (size_t k = 0; k < pair.size() / 2; ++k)
                result.push_back(vector<int> {*i, pair[k * 2], pair[k * 2 + 1]});
            lastnum = *i;
        }
        return result;
    }
};

int main() {
    Solution solution;
    // vector<int> arr {-1, 0, 1, 2, -1, -4}; // -4 -1 -1 0 1 2
    vector<int> arr {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    for (auto i : solution.threeSum(arr)) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    } 
    return 0;
}
