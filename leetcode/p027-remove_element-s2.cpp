/*
27
Remove Element 
https://leetcode.com/problems/remove-element/


Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


(EASY)  Array, Two Pointers
*/

/*

The second solution uses two pointers as one leading and one following.
The idea is similar to problem 26. 
This solution maintains the original order of the array.

112 / 112 test cases passed.
Status: Accepted
Runtime: 5 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem)
    {
        int following = 0;
        int leading = 0;
        while (leading < n)
            if (A[leading] == elem) ++leading; else A[following++] = A[leading++];
        return following;
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
