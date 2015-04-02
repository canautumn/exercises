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
SOLUION 3 (Recursion level by level, using the similar method as Solution 2 
for each level):

Just for fun. The iteration is so natural that using recursion looks so 
unnecessary.

It is almost the same as Solution 2, but it needs to find a good way to jump 
over '.'. If we do this like Solution 2, passing (i+1) to substr(), 
segmentation fault will happen at the end (substr doesn't check inputs). 
One way is to check it before passing (like the Alternative solution below). 
Another way is to pass (i), (which is guaranteed to be valid for substr), and 
check '.' at the beginning of the recursion. See below.

Also, an recursion version using find, substr, and stoi can also be done.

SOLUTION (ALTERNATIVE):
class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (!version1.size() && !version2.size()) return 0;
        int i = 0, j = 0;
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
        else return compareVersion(version1.substr(min(i+1,(int)version1.size())), 
                                   version2.substr(min(j+1,(int)version2.size())));
        
        return 0;
    }
};

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
        if (!version1.size() && !version2.size()) return 0;
        // cout << version1 << " " << version2 << endl;
        int i = 0, j = 0;
        int v1 = 0, v2 = 0;
        
        if (version1[i] == '.') i++;
        if (version2[j] == '.') j++;
        
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
        else return compareVersion(version1.substr(i), version2.substr(j));
        
        return 0;
    }
};

int main() {
    Solution solution;
    cout << solution.compareVersion("1.142.0.0.0.0", "1.142.0.0.0.0.1.0") << endl;
    return 0;
}
