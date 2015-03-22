/*
66
Length of Last Word
https://leetcode.com/submissions/detail/23649224/


Given a non-negative number represented as an array of digits, plus one to the 
number.

The digits are stored such that the most significant digit is at the head of 
the list.

(EASY) Array Math
*/

/*
108 / 108 test cases passed.
Status: Accepted
Runtime: 5 ms
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i]++;
            if (digits[i] < 10) break;
            digits[i] = 0;
            if (i == 0) digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution solution;
    vector<int> digits {9,9,9};
    digits = solution.plusOne(digits);
    for (auto c : digits) {
        cout << c;
    }
}
