/*
189
Rotate Array
https://leetcode.com/problems/rotate-array/


Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to 
[5,6,7,1,2,3,4].

Note:

Try to come up as many solutions as you can, there are at least 3 different 
ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.


(EASY) Array
*/

/*
SOLUTION 1 ():

33 / 33 test cases passed.
Status: Accepted
Runtime: 32 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        int counter = 0;
        for (int start = n - 1; start > n - 1 - k; --start) {
            // cout << start << endl;
            int i = start;
            int temp = nums[i];
            do {
                i -= k;
                if (i < 0) {
                    nums[i + k] = nums[i + n];
                    i += n;
                } else {
                    nums[i + k] = nums[i];
                }
                counter++;
            } while (i != start);
            nums[k - 1 - (n-1-start)] = temp;
            if (counter == n) break;
        }
    }
};

int main() {
    Solution solution;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(arr, 7, 3);
    for (int i = 0; i < 7; ++i) cout << arr[i] << endl;

    cout << endl;
    int arr2[] = {1, 2, 3, 4, 5, 6};
    solution.rotate(arr2, 6, 4);
    for (int i = 0; i < 6; ++i) cout << arr2[i] << endl;
    
    return 0;
}
