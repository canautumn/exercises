/*
11
Container With Most Water
https://leetcode.com/problems/container-with-most-water/


Given n non-negative integers a1, a2, ..., an, where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container.


(MEDIUM) Array, Two Pointers
*/

/*
SOLUTION:

The idea is to start from the container with the largest width. Then figure 
what to do when moving either side of the edge to the center. Observation:

1. For each step, to improve the container, you have to move the shorter edge. 

2. When moving the shorter edge, only when the new edge is higher than the 
current edge, should the area have the chance to get larger. (But not 
necessarily; we still need to check.)

3. But when the short edge is moved such that it is higher than the other edge, 
we should go on to the next iteration to move the new 'shorter' edge. Because 
the current side is higher than the other side now, we should move the new 
lower edge.

The loop ends when left and right edge meets. An initial implementation is as 
below:


    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int maxArea = min(height[left], height[right]) * (right - left);
        while (left < right - 1) {
            if (height[left] < height[right]) {
                int i = left;
                while (i < right) {
                    i++;
                    if (height[i] > height[left]) {
                        if (height[i] > height[right]) {
                            maxArea = max(height[right] * (right - i), maxArea);
                            left = i;
                            break;
                        } else {
                            maxArea = max(height[i] * (right - i), maxArea);
                        }
                    }
                }
                left = i;
            } else {
                int i = right;
                while (i > left) {
                    i--;
                    if (height[i] > height[right]) {
                        if (height[i] > height[left]) {
                            maxArea = max(height[left] * (i - left), maxArea);
                            right = i;
                            break;
                        } else {
                            maxArea = max(height[i] * (i - left), maxArea);
                        }
                    }
                }
                right = i;
            }
        }
        return maxArea;
    }

A pitfall is that since we have a inner loop that guarantees the left and 
right pointer not meeting with each other, the loop condition for the outer 
loop is 'left < right - 1', not 'left < right'.

Actually, the observation 2 is not necessary to specifically take care of. As 
long as we always move the lower edge, we don't need to check if the moved 
edge is higher than before. Without this check, the only downside is that we 
will check the area every time we move the edge. Only a few multiplication is 
added and it is not much overhead, which is negligible. However, without this 
additional check, we can eliminate the two inner loops above, and get a much 
simplified program as below. 

Tips:
The loop body can be written in one line as below:

            result = height[left] >= height[right] ? 
                     max((right - left) * height[right--], result) : 
                     max((right - left) * height[left++], result);

Clang 3.5 gives warning:

    warning: unsequenced modification and access to '...' [-Wunsequenced]
    
This one-liner should run fine regardless the warning but it is not a good 
practice. One-liners sometimes are evil.


45 / 45 test cases passed.
Status: Accepted
Runtime: 31 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1, result = 0;
        while (left < right) {
            if (height[left] >= height[right]) {
                result = max((right - left) * height[right], result); 
                right--;
            } else {
                result = max((right - left) * height[left], result); 
                left++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr {3, 1, 2, 3};
    cout << solution.maxArea(arr) << endl;
    return 0;
}
