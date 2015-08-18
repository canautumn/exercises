/*
223
Rectangle Area
https://leetcode.com/problems/rectangle-area/


Description:

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as 
shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image 
and all test cases.

(EASY) Math
Similar Problems: 
*/

/*
SOLUTION 2: 

Check the coordinates first. Only if all of the 4 pairs of sides (determined by 
corresponding coordinates) meet some condition, the area could be overlapped.
Only in this case the overlapped area is calculated and subtracted.

This can avoid the intermediate overflow since no unnecessary pre-calculation 
is needed. For example, when C = -LARGENUM, E = LARGENUM, C-E will never be 
calculated since they don't meet the condition C > E. However, if you check 
the overlapping after the C-E calculation (as in Solution 1), the result is 
already overflowed when checking. On the other hand, there is no case when 
C = LARGENUM, E = -LARGENUM, in which case if C, E are involved in the 
overlapped area calculation, C < G and E > A. C - E is also the width of the 
overlapped area. So if C - E overflows, the total area must be overflowed. 
Thus this case won't happen.


[*]
3081 / 3081 test cases passed.
Status: Accepted
Runtime: 28 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C > E && G > A && H > B && D > F) ? 
               (C - A) * (D - B) + (G - E) * (H - F) - 
               (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)) : 
               (C - A) * (D - B) + (G - E) * (H - F);
    }
};

int main() {
    Solution solution;
    cout << solution.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    cout << solution.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << endl;
    cout << solution.computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl;
    cout << solution.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;
    
    return 0;
}
