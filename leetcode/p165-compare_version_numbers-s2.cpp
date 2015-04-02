/*
165
Compare Version Numbers
https://leetcode.com/problems/compare-version-numbers/


Compare two version numbers version1 and version2.

If version1 > version2 return 1, if version1 < version2 return -1, otherwise 
return 0.

You may assume that the version strings are non-empty and contain only digits 
and the . character.

The . character does not represent a decimal point and is used to separate 
number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it 
is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.


(EASY) String
*/

/*
SOLUION 2 (Iteration on the string char by char, without using library 
functions):

The code could be simpler if iterating the string and converting numbers 
without using string library functions, avoiding dealing with multiple inputs 
and outputs of those functions in this simple case. 

The key is from left to right using 
    v1 = v1 * 10 + new_char - '0';
automatically converts the string to number in one pass, and using isdigit() 
to stop the conversion, and jumps to next char in both strings (which must be 
'.')

This method automatically considers the cases like '1.0' vs '1', since at some 
level, if one string's iteration ends, the version number is 0 such that it 
can be compared with the other one.

(Based on https://leetcode.com/discuss/29801/my-c-solution-2ms )

Tips:
- isdigit() is a C function in header cctype.
- v1 and v2 can be declared once outside the loop, and reused each time. But 
the performance improvement is ignorable. On the other hand, declare them 
inside the loop clear shows the meaningful lifecycle of them.

69 / 69 test cases passed.
Status: Accepted
Runtime: 2 ms
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() || j < version2.size()) {
            int v1 = 0, v2 = 0;
            for (; i < version1.size() && isdigit(version1[i]); ++i) {
                v1 = v1 * 10 + version1[i] - '0';
            }
            for (; j < version2.size() && isdigit(version2[j]); ++j) {
                v2 = v2 * 10 + version2[j] - '0';
            }
            
            if (v1 < v2) 
                return -1;
            else if (v1 > v2)
                return 1;
            i++;
            j++;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    cout << solution.compareVersion("1.142.0.0.0.0", "1.142.0.0.0.0.1.0") << endl;
    return 0;
}
