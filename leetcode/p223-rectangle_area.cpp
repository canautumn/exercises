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
SOLUTION: 

Calculate the area of two rectangles. Then minus the duplicated area.

To calculate the duplicated area, the top-right and bottom-left corner should 
be found. Simply, find the smaller x, y of the two top-right x, y respectively, 
and larger x, y of the two left-bottom x, y respectively.

Pitfalls:
- Note the '?:' operator has a lower priority.
- When either of the two side of the "duplicated rectangle" according to the 
coordinates calculated by the method above is negative, the duplicated area 
should be zero. Do not check the production of the two side directly since both 
of them can be negative, in which case the duplicated area should be zero.
- Intermediate result overflow. Although the result is said to be not overflow, 
since subtraction is involved, some intermediate result could be overflow. 
However, some methods can avoid this. See Solution 2.

[5mxxx]
3081 / 3081 test cases passed.
Status: Accepted
Runtime: 40 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long total = (C - A) * (D - B) + (G - E) * (H - F);
        long duplicated_s1 = long(C < G ? C : G) - long(A > E ? A : E);
        long duplicated_s2 = long(D < H ? D : H) - long(B > F ? B : F);
        if (duplicated_s1 <= 0 || duplicated_s2 <= 0) return total;
        return total - duplicated_s1 * duplicated_s2;
    }
};

int main() {
    Solution solution;
    cout << long(-1500000000) - long(1500000000) << endl;
    cout << solution.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    cout << solution.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << endl;
    cout << solution.computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl;
    cout << solution.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;
    
    return 0;
}
