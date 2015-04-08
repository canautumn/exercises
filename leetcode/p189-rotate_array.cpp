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
SOLUTION 1 (Find the 'rings' of rotations):

It is definitely not the simplest solution but it is how I think about it when 
I first met it: Write down some simple cases, find rules and solve problems.

Observe these two examples:

1) n = 10, k = 3

>             +----->
V             |
+-----+       |
|     V       |
|     +-----+ |
|     |     V |
|     |     +-----V
1 2 3 4 5 6 7 8 9 0
8 9 0 1 2 3 4 5 6 7

See the rotation from the end, 0 is now 7, 7 is now 4, ..., whenever find the 
new number that should fill into a position, find this number's location and 
see what should be in there (and it is actually the number at the position 
that counts k before the current position), and it is a rotation loop: Go on 
and see when the rotation is back to the original position (the last position), 
fill in the number that is 'originally' there (here is '0' for old '3'). So 
the only number we should back up is '0', the number we started with, to be 
put in the last position. 

So it is actually a loop, and you can start wherever you want. Start from the 
last position is straightforward. Back up the first number, replace it with 
the number k locations before it (and if it goes before the first location -- 
pointer less than 0 -- just add n to the pointer to rotate back into the 
array), and go on to process the number that just used. The key here is that 
we don't rotate the numbers one by one, but rotate them and jumping back k by 
k. If we do it one by one, we have to use O(k) ~ O(n) space to back up all the 
numbers encountered before reach k locations. 

Because in this case, 7 and 3 has a greatest common divisor of 1, the loop is 
guaranteed to cover all locations after it comes back to where we started. 

But how about those n and k having greatest common divisor larger than 1? It 
is possible that the pointer reaches back to the original position without 
covering all locations. Try that. See case 2):

2) n = 6, k = 4;

1 2 3 4 5 6
3 4 5 6 1 2

If we run the method above once, it would be 1 4 3 6 5 2, it is clear that we 
have to shift the position by 1 (from 5) and start to run it again to cover 1, 
3, 5. So the maximum possible shift position is k, since n - 1 - k must be 
processed in the first loop. But it is not always that many
shift-and-run-again's -- if we do more than necessary, it will be wrong. So do 
we have to calculate the greatest common divisor between n and k? (It will 
certainly find out how many loops we need to do.) No. A simple way is to just 
find out how many locations we have processed. Because the number of locations 
we processes must be exact n.

Pitfalls:

Finally, recognize a pitfall of this method: k could be larger than n (and 
even several times larger). To deal with it, we have to let k = k % n, and it 
is equivalent to k.


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
