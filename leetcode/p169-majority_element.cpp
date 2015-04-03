/*
169
Majority Element
https://leetcode.com/problems/majority-element/


Given an array of size n, find the majority element. The majority element is 
the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always 
exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


(EASY) Divide and Conquer, Array, Bit Manipulation
*/

/*
SOLUTION 1 (Moore Voting):

Note that the input is guaranteed to have a majority (also non-empty). If the 
input is not guaranteed to have a majority, the Moore voting algorithm will 
still give an element, but it is not correct (and not necessarily the element 
that has the largest count in the array). In this case an additional iteration 
on the array is required to determine whether the output is a majority.

Therefore, be careful when constructing test cases.


( http://www.geeksforgeeks.org/majority-element/ ) gives a solution similar to 
below. Note that it initialize the count and maj_index for the first element, 
and start from the second element. Also, it uses maj_index instead of majority 
it self, which is not necessary if we want to know the majority itself. 

    int majorityElement(vector<int> &num) {
        int count = 1, maj_index = 0;
        for (int i = 1; i < num.size(); ++i) {
            if (num[maj_index] == num[i]) count++; else count--;
            if (count == 0) {
                maj_index = i;
                count = 1;
            }
        }
        return num[maj_index];
    }

With a little bit of tweaking statement order to optimize the workflow, an 
equivalent algorithm is given in the program below.


LEETCODE SOLUTION: 

- Runtime: O(n2) — Brute force solution: Check each element if it is the 
majority element.

- Runtime: O(n), Space: O(n) — Hash table: Maintain a hash table of the counts 
of each element, then find the most common one.

- Runtime: O(n log n) — Sorting: As we know more than half of the array are 
elements of the same value, we can sort the array and all majority elements 
will be grouped into one contiguous chunk. Therefore, the middle (n/2th) 
element must also be the majority element.

- Average runtime: O(n), Worst case runtime: Infinity — Randomization: 
Randomly pick an element and check if it is the majority element. If it is 
not, do the random pick again until you find the majority element. As the 
probability to pick the majority element is greater than 1/2, the expected 
number of attempts is < 2.

- Runtime: O(n log n) — Divide and conquer: Divide the array into two halves, 
then find the majority element A in the first half and the majority element B 
in the second half. The global majority element must either be A or B. If 
A == B, then it automatically becomes the global majority element. If not, 
then both A and B are the candidates for the majority element, and it is 
suffice to check the count of occurrences for at most two candidates. The 
runtime complexity, T(n) = T(n/2) + 2n = O(n log n).

- Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and 
a counter initialized to 0. As we iterate the array, we look at the current 
element x:

  - If the counter is 0, we set the current candidate to x and the counter to 1.
  
  - If the counter is not 0, we increment or decrement the counter based on 
  whether x is the current candidate.

  - After one pass, the current candidate is the majority element. Runtime 
  complexity = O(n).

- Runtime: O(n) — Bit manipulation: We would need 32 iterations, each 
calculating the number of 1's for the ith bit of all n numbers. Since a 
majority must exist, therefore, either count of 1's > count of 0's or vice 
versa (but can never be equal). The majority number’s ith bit must be the one 
bit that has the greater count.

Update (2014/12/24): Improve algorithm on the O(n log n) sorting solution: We 
do not need to 'Find the longest contiguous identical element' after sorting, 
the n/2th element is always the majority.


40 / 40 test cases passed.
Status: Accepted
Runtime: 26 ms
*/


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0, majority;
        for (auto i : num) {
            if (count == 0) majority = i;
            if (majority == i) count++; else count--;
        }
        return majority;
    }
};

int main() {
    Solution solution;
    vector<int> num {1, 2, 1, 1, 3, 3, 1};
    cout << solution.majorityElement(num) << endl;
    vector<int> num2 {6, 5, 5};
    cout << solution.majorityElement(num2) << endl;
    
    return 0;
}
