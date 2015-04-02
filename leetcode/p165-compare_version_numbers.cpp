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
SOLUION 1 (Iteration, using string functions):
Use find (and string::npos), substr, and stoi to compare version number level 
by level. 

Then consider the case that '1.0.0' is the same as '1'. Here a helper 
'compare_leftover' is used to determine if the left over levels are all 0's.

To keep the code a little simpler, append '.' at the end so each level always 
ends by '.'.

The code could be simpler if iterating the string and converting numbers 
without using string library functions, avoiding dealing with multiple inputs 
and outputs of those functions in this simple case. See Solution 2.

Tips:
- stoi is C++11 function in header string that is similar to atoi or atol in 
cstring.

69 / 69 test cases passed.
Status: Accepted
Runtime: 2 ms
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static inline int compare_leftover(string leftover, int default_output) {
        int last_pos = -1;
        while (true) {
            int curr_pos = leftover.find('.', last_pos + 1);
            if (curr_pos == string::npos) break;
            if (stoi(leftover.substr(last_pos + 1, curr_pos - last_pos - 1)) != 0) 
                return default_output;
            last_pos = curr_pos;
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        int curr_pos1 = 0; int curr_pos2 = 0, last_pos1 = -1, last_pos2 = -1;
        version1.append("."); version2.append(".");
        while (true) {
            int v1 = 0, v2 = 0;
            curr_pos1 = version1.find('.', last_pos1 + 1);
            curr_pos2 = version2.find('.', last_pos2 + 1);
            
            if (curr_pos1 != string::npos) {
                v1 = stoi(version1.substr(last_pos1 + 1, curr_pos1 - last_pos1 - 1));
            } else {
                return (curr_pos2 != string::npos) ? 
                        compare_leftover(version2.substr(last_pos2 + 1), -1) : 0;
            }
            
            if (curr_pos2 != string::npos) {
                v2 = stoi(version2.substr(last_pos2 + 1, curr_pos2 - last_pos2 - 1));
            } else {
                return (curr_pos1 != string::npos) ? 
                        compare_leftover(version1.substr(last_pos1 + 1), 1) : 0;
            }
            
            if (v1 == v2) {
                last_pos1 = curr_pos1;
                last_pos2 = curr_pos2;
                continue; 
            } else {
                return v1 > v2 ? 1 : -1;
            }            
        }
    }
};

int main() {
    Solution solution;
    cout << solution.compareVersion("1.142.0.0.0.0", "1.142.0.0.0.0.1.0") << endl;
    return 0;
}
