/*
26
Remove Duplicates from Sorted Array
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/


Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].


(EASY)  Array, Two Pointers
*/

/*

Corner cases:
- n = 0, n = 1.
- Especially n=0. 'trailing' is an 'index', we will return a "count', so we need to return
    trailing+1, however, this breaks when n=0.
- Pointer moving before or after reference.

9m
161 / 161 test cases passed.
Status: Accepted
Runtime: 36 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int leading = 1;
        int trailing = 0;
        while (leading < n) {
            if (A[leading] == A[leading - 1]) {
                leading++;
                continue;
            }
            A[++trailing] = A[leading++];
        }
        return trailing+1;
    }
};

int main() {
    Solution solution;
    int a[] = {1, 1, 2};
    int n = solution.removeDuplicates(a, 3);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    int b[] = {1, 1, 2, 5, 5, 5};
    n = solution.removeDuplicates(b, 6);
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
    int c[] = {1, 2};
    n = solution.removeDuplicates(c, 2);
    for (int i = 0; i < n; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;
}
