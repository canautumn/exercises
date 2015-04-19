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
SOLUTION 2: (Sort and Two Pointers)

Sort the array (O(nlogn)) then use two pointers starting from the two ends of 
the array. Since the array is sorted, each step there is only one choice we 
could make, either increasing left pointer if the current sum is less than the 
target, or decreasing right pointer if the current sum is larger than the 
target. This makes it O(n). The total time is O(nlogn). 

If the problem only asks for the value of the two numbers, the code is simpler:
(Pitfall: trivial case when the array has 0 or 1 elements need to be taken 
care of.)


    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        if (numbers.size() < 2) return result;
        sort(numbers.begin(), numbers.end());
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                result.push_back(numbers[left]);
                result.push_back(numbers[right]);
                return result;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }


However, the problem asks for the index. We need to know the original index 
before sorting. 

The first implementation is to use a lambda expression to tell std::sort to 
sort an index array but use the value in the 'numbers' vector that indexed 
by the indexes. So the index array needs to be filled with the ascending 
original indexes before sorting, using a loop, or std::iota. 

Pitfall:

- Note that the 'numbers' is not actually sorted. So we need to index twice 
to get a value, such as 'numbers[sorted_indexes[left]]'. See the program.

- The OJ only accepts index pair with ascending order. This is not a problem 
with the hash map solution but since we sorted the array, the original indexes 
could be reversed. This needs to be taken care of when pushing results. 

A second method is to use a data structure storing both value and index of 
each element (e.g., std::pair), and sorting based on the value. This can be 
done by specifying a lambda expression or a function pointer to std::sort to 
tell it sorting with the value of each element, not index. See below:


    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        if (numbers.size() < 2) return result;
        vector<pair<int, size_t>> numberidx;
        int k = 1;
        for (auto i : numbers) numberidx.push_back(make_pair(i, k++));
        sort(numberidx.begin(), numberidx.end(), [](pair<int, size_t> pair1, pair<int, size_t> pair2) { 
            return pair1.first < pair2.first; 
        });
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numberidx[left].first + numberidx[right].first == target) {
                result.push_back(numberidx[left].second < numberidx[right].second ? numberidx[left].second : numberidx[right].second);
                result.push_back(numberidx[left].second < numberidx[right].second ? numberidx[right].second : numberidx[left].second);
                return result;
            } else if (numberidx[left].first + numberidx[right].first < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
    

The problem assumes there exist only one pair of results. However, the program 
can go on to process more results by replacing 'return' with 'left++;right--;'. 
Take the version only outputs value not indexes as an example, see below:


    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        if (numbers.size() < 2) return result;
        sort(numbers.begin(), numbers.end());
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                result.push_back(numbers[left]);
                result.push_back(numbers[right]);
                left++;
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }


Although hash map method has a lower time complexity O(n), it could be slower 
on the OJ than this O(nlogn), probably because of the overhead of STL.


[*]
16 / 16 test cases passed.
Status: Accepted
Runtime: 24 ms
*/


#include <iostream>
#include <vector>
#include <numeric> // iota

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        if (numbers.size() < 2) return result;
        vector<size_t> idx(numbers.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&numbers](size_t idx1, size_t idx2) { 
            return numbers[idx1] < numbers[idx2]; 
        });
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
                if (numbers[idx[left]] + numbers[idx[right]] == target) {
                result.push_back(idx[left] < idx[right] ? idx[left] + 1 : idx[right] + 1);
                result.push_back(idx[left] < idx[right] ? idx[right] + 1 : idx[left] + 1);
                return result;
            } else if (numbers[idx[left]] + numbers[idx[right]] < target) {
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
    vector<int> arr {2, 7, 11, 15};
    for (auto i : solution.twoSum(arr, 9)) cout << i << endl;
    return 0;
}
