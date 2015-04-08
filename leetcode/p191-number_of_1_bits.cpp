/*
190
Reverse Bits
https://leetcode.com/problems/reverse-bits/


Write a function that takes an unsigned integer and returns the number of ’1' 
bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 
00000000000000000000000000001011, so the function should return 3.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


(EASY) Bit Manipulation
*/

/*
(Bit manipulation):
Retrieve last bit, add it to the counter, and shift n to the right.

Tips:

- 'n >> 1' is an expression that doesn't change n. 'n >>= 1' is used to change 
n by shift one bit. This is sometimes easy to be confused with. Clang will 
give a warning on 'n >> 1' that the result of the expression is unused. 

- 0b prefix can be used to denote binary literal (such as 0b1011) in GCC and 
Clang as an extension, as well as in the C++14 standard.


[1min]
600 / 600 test cases passed.
Status: Accepted
Runtime: 12 ms
*/


#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n > 0) {
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.hammingWeight(0b1011) << endl;
    
    return 0;
}
