/*
88
Merge Sorted Array 
https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) 
to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

(EASY) Array, Two Pointers
*/

/*
Since A has enough space after the end for B, it is better to process from 
the end where A has 'unused' space.

Pitfall: Deal with the case where one of A and B has ended iterating but 
another one still needs copying elements in place. Furthermore, when B ends 
iterating first, the loop can be ended since A's first several elements are 
already in place.

59 / 59 test cases passed.
Status: Accepted
Runtime: 6 ms
*/

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        for (int k = m + n - 1; k >= 0; --k) {
            if (i < 0) {
                A[k] = B[j--];
            } else if (j < 0) {
                break; // A[k] = A[i--]; is unnecessary
            } else if (A[i] >= B[j]) {
                A[k] = A[i--];
            } else {
                A[k] = B[j--];
            }
        }
    }
};

int main() {
    Solution solution;
    int A[] = {5, 5, 5, 8, 9, 9, 13, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0};
    int B[] = {1, 3, 3, 4, 7, 8, 19, 29};
    int m = 9, n = 8;
    solution.merge(A, m, B, n);
    for (int i = 0; i < m + n; ++i) {
        cout << A[i] << " ";
    }

}
