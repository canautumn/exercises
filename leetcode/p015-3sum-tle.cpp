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
SOLUTION: (Modify Two Sum problem and use hash set)
*/


#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    class VectorIntHash
    {
    public:
        std::size_t operator()(const vector<int> &v) const
        {
            std::size_t x = 0;
            for (auto &i : v)
                x ^= std::hash<int>()(i);
            return x;
        }
    };

public:
    vector<int> twoSum(const vector<int> &numbers, int target) { // changed to const
        map<int, int> target_to_sourceidx;
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i) {
            if (target_to_sourceidx.find(numbers[i]) == target_to_sourceidx.end()) {
                target_to_sourceidx[target - numbers[i]] = i;
            } else {
                result.push_back(numbers[target_to_sourceidx[numbers[i]]]);
                result.push_back(numbers[i]);
            }
        }
        return result;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        unordered_set<vector<int>, VectorIntHash> result_set;
        if (num.size() < 3) return vector<vector<int>>();
        sort(num.begin(), num.end());
        for (auto i = num.begin(); i != num.end() - 2; ++i) {
            auto pair = twoSum(vector<int> (i + 1, num.end()), -(*i));
            for (size_t k = 0; k < pair.size() / 2; ++k)
                result_set.insert(vector<int> {*i, pair[k * 2], pair[k * 2 + 1]});
        }
        return vector<vector<int>>(result_set.begin(), result_set.end());
    }
};

int main() {
    Solution solution;
    vector<int> arr {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    for (auto i : solution.threeSum(arr)) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    } 
    return 0;
}
