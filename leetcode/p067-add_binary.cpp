/*
67
Add Binary 
https://leetcode.com/problems/add-binary/

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

(EASY) Math, String
*/

/*
The last carry is not easy to be predicted without iteration from the end of 
the strings. To iterate from the lowest digit, the two strings need to be 
aligned from the end. To get faster result insertion, either pre-reserve 
enough elements for the result string, append each time, and reversely iterate 
at the end to get the result, or use a deque. Insert a char at the beginning 
of the result string could be slower than appending at the end.

Also, deque's push_front is O(1), which is faster than inserting a char in 
front of a string.

294 / 294 test cases passed.
Status: Accepted
Runtime: 7 ms
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        deque<char> r;
        int n, aoffset, boffset;
        if (a.size() >= b.size()) {
            n = a.size();
            aoffset = 0;
            boffset = a.size() - b.size();
        } else {
            n = b.size();
            boffset = 0;
            aoffset = b.size() - a.size();
        }
        short carry = 0;
        for (int i = n - 1; i >= 0; --i) {
            short ac = i - aoffset >= 0 ? a[i - aoffset] - '0' : 0;
            short bc = i - boffset >= 0 ? b[i - boffset] - '0' : 0;
            short val = ac + bc + carry;
            carry = val / 2;
            r.push_front((val % 2) + '0');
        }
        if (carry == 1) r.push_front('1');
        string result;
        result.reserve(r.size());
        for (auto c : r) {
            result.append(1, c);
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.addBinary("100", "1100") << endl;
    cout << solution.addBinary("0", "0") << endl;
    cout << solution.addBinary("1", "111") << endl;
    cout << solution.addBinary("1111", "1100") << endl;
}
