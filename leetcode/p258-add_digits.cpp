/*
258
Add Digits
https://leetcode.com/problems/add-digits/


Description:

Given a non-negative integer num, repeatedly add all its digits until the 
result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only 
one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all 
test cases.

(EASY) Math
Similar Problems: 202 Happy Number
*/

/*
SOLUTION: 

Tips:
- A Naive solution would be:

        while (num >= 10) {
            num = num % 10 + num / 10;
        }
        return num;

which would also run 8ms for those test cases. However, a better way is to 
observe some rules.

1. Observe that the results are all single digits, i.e., 0 to 9.
2. The digits are recurring periodically. 
3. The special case is num = 0, which is the only number that yields 0.
4. Use the modulus to get correct recurring results:

        return (num - 1) % 9 + 1;

Pitfalls:
- Modulus of N is from 0 to 9. However, the rule we observed is not. It is 
shifted by one both in the 'input' and 'output' side. So this is simply wrong:
(for numbers like 9, 18 ...)

        return num % 9;

So make sure to validate some results. The shifted modulus is very often used.

[*]
1101 / 1101 test cases passed.
Status: Accepted
Runtime: 8 ms
*/


#include <iostream>
    
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main() {
    Solution solution;
    cout << solution.addDigits(38) << endl;
    cout << solution.addDigits(9) << endl;
     
    return 0;
}
