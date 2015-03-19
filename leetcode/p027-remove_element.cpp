/*
27
Remove Element 
https://leetcode.com/problems/remove-element/


Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


(EASY)  Array, Two Pointers
*/

/*

Since the order can be changed, there is no need to really remove elements and move all elements beyond it.
(Although it is not difficult to do this in one pass using two pointers, as in Solution 2.)
So we can just fill the element to be removed with the last element.
A pitfall is that it is better to use while loop than for loop since the pointer is not always moving.

112 / 112 test cases passed.
Status: Accepted
Runtime: 5 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        while (i < n)
            if (A[i] == elem) A[i] = A[--n]; else ++i;
        return n;
    }
};

int main() {
    Solution solution;
    int a[] = {1, 1, 2, 2, 3, 5, 9, 11, 11, 13, 15};
    int n = solution.removeElement(a, 11, 2);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    int b[] = {1, 1, 1, 1, 1, 1};
    n = solution.removeElement(b, 6, 1);
    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}
