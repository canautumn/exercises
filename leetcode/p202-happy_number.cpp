/*
202
Happy Number
https://leetcode.com/problems/happy-number/


Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any 
positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), or it 
loops endlessly in a cycle which does not include 1. Those numbers for which 
this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all 
test cases.


(EASY) Hash Table, Math
Similar Problems: 258 Add Digits
*/

/*
SOLUTION: Hash Table

Use hash table to record any emerged numbers to detect infinite loops.

[10min]
400 / 400 test cases passed.
Status: Accepted
Runtime: 4 ms
*/


#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> emerged;
        while(true) {
            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10; 
            }
            if (sum == 1) return true;
            if (emerged.find(sum) != emerged.end()) return false;
            emerged.insert(sum);
            n = sum;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.isHappy(1) << endl;
    
    return 0;
}
