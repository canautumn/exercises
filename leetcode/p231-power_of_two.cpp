/*
231
Power of Two
https://leetcode.com/problems/power-of-two/


Description:

Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating 
all test cases.

(EASY) Math, Bit Manipulation
Similar Problems: 191 Number of 1 Bits
*/

/*
SOLUTION: (Bit Manipulation - Bit-Shift and Loop)

Take a look at the numbers that are the power of 2, obviously better in the 
perspective of binary numbers:

- There is only one '1'. All other digits are '0'.

One way is to right shift the bits until you get 1. Before that, once the last 
bit (obtained by bit-and with 1) is 1 (and the value is not 1), the number is 
not the power of two, and you can return false.

The code is as below. To be more concise, another variant is:

    while (!(n & 1) && n > 0) n >>= 1;
    return n == 1;

There are many other concise methods. Since they are very concise, they will 
not be listed in another file.

SOLUTION 2 (Bit Manipulation - Bit-And):

- The power of 2 all like 10000...0 and if 1 is subtracted from it, we get 
01111...1. The bit-and between them should be 0.

    return n > 0 && !(n & (n - 1));

SOLUTION 3 (Recursion):

- This is a tailed recursion version of SOLUTION 1:

    if(n == 0)              return false;
    if(n == 2 || n == 1)    return true;
    if(n%2 != 0)            return false;
    else                    return isPowerOfTwo(n>>1);
    
SOLUTION 4 (log2 and floor)

- log2() is also very fast.

    return (int)log2(n) == log2(n);

(All the solutions runs 8ms for the test set.)



Pitfalls:
- Bit shift means shifting the number, not the dot.


[5mx]
1108 / 1108 test cases passed.
Status: Accepted
Runtime: 8 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n > 0) {
            if (n == 1) return true;
            if (n & 1) return false;
            n >>= 1;
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.isPowerOfTwo(1024);
    
    return 0;
}
