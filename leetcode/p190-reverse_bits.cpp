/*
190
Reverse Bits
https://leetcode.com/problems/reverse-bits/


Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 
00000010100101000001111010011100), return 964176192 (represented in binary as 
00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


(EASY) Bit Manipulation
*/

/*
(Bit manipulation):
Retrieve one bit, save it to the result. Shift n to the right and shift result 
to the left. Do this 32 times (don't stop when n is zero).

Tips:
result <<= 1; result |= d; can be written as (result <<= 1) |= d; (parentheses 
are necessary) but there is no good reason to do so.

600 / 600 test cases passed.
Status: Accepted
Runtime: 9 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            bool d = n & 1;
            n >>= 1;
            result <<= 1;
            result |= d;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.reverseBits(43261596) << endl;
    
    return 0;
}
