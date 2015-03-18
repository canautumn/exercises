/*
8
Palindrome Number
https://oj.leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

(EASY)
*/

/*
First is to find the order of the number (or 10 to the number of digits). This can be done by
        pow(10, floor(log10(x)))
Another way without using log10 or pow, is to add a loop (which will increase the time to 236ms).
        int left = 1;
        int copy = x;
        while (copy >= 10) {
            copy /= 10;
            left *= 10;
        }
        
A simpler solution is to reverse the number on the fly, which doesn't require additional steps for the order.
However, this does not handle the overflow. Some people make a copy of long to avoid it.

Another solution is to cut the digits in two halves, and reverse the right side. This will not cause overflow.

11505 / 11505 test cases passed.
Status: Accepted
Runtime: 126 ms
*/


#include<iostream>
#include<complex>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int left = pow(10, floor(log10(x)));
        int right = 1;
        while (left > right) {
            if ((x / left) % 10 != (x / right) % 10) {
                return false;
            }
            left /= 10;
            right *= 10;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(9252529) << endl;
}