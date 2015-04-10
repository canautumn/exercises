/*
5
Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/


Given a string S, find the longest palindromic substring in S. You may assume 
that the maximum length of S is 1000, and there exists one unique longest 
palindromic substring.


(MEDIUM) String
*/

/*
SOLUTION 1 (DP, O(n^2) space):

First write a recursive solution. This is clearly an overlapping subproblem 
case. And the recursive solution will be not practical:

    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        if (s.length() == 1) return s;
        if (s[0] == s[s.length() - 1]) {
            string s1 = longestPalindrome(s.substr(1, s.length() - 2));
            if (s1.length() == s.length() - 2) {
                return s;
            }
        }
        string s1 = longestPalindrome(s.substr(0, s.length() - 1));
        string s2 = longestPalindrome(s.substr(1, s.length() - 1));
        return s1.length() > s2.length() ? s1 : s2;
    }

Translate it into a dynamic programming version. Use a bool table[i][j] to 
record whether substring indexed by i to j is a palindrome. Build the table 
with length (j - i + 1) from 1 to s.size(). This solution is practical enough 
to get a long string's solution quickly.

Pitfall: carefully examine the termination condition of 'i' 
(s.size() - len + 1). If 'i' missed the last letter, it might only fail at a 
few edge cases and difficult to debug.

DP solution's time complexity is O(n^2). The OJ will give TLE if 
vector<vector<int>> is used as the look up table because of the overhead. 
Change it to bool[1000][1000] array will just pass the OJ.

Also, DP solution uses O(n^2) space, which can be easily optimized to O(n) 
space (by discarding information that represents substrings with lengths less 
than len - 2) but not shown here.

There is a O(n^2) time O(1) space solution that makes use of the palindrome's 
property. See Solution 2.

And there will be O(n) solution for this problem. See Solution 3. DP is not 
always the best method.


88 / 88 test cases passed.
Status: Accepted
Runtime: 475 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        // vector<vector<bool>> table(s.length(), vector<bool>(s.length(), false)); // SLOW
        bool table[1000][1000];
        for (int i = 0; i < s.length(); ++i)
            for (int j = 0; j < s.length(); ++j)
                table[i][j] = false;
        
        int longest_length = 1, longest_i = 0;
        for (int len = 1; len <= s.size(); ++len) {
            for (int i = 0; i < s.size() - len + 1; ++i) { // note the termination condition
                int j = i + len - 1;
                // cout << i << "," << j << endl;
                if (j == i) table[i][j] = true;
                else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        table[i][j] = true;
                        if (2 > longest_length) {
                            longest_length = 2;
                            longest_i = i;
                        }
                    }
                    // else table[i][j] = false; // no need since it is initialized to false
                } else {
                    if (s[i] == s[j] && table[i+1][j-1]) {
                        table[i][j] = true;
                        if (j - i + 1 > longest_length) {
                            longest_length = j - i + 1;
                            longest_i = i;
                        }
                    }
                }
            }
        }
        // cout << longest_i << " " << longest_length << endl;
        return s.substr(longest_i, longest_length);
    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("ccccbabcdmm") << endl;
    cout << solution.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << endl;
    cout << solution.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
    cout << solution.longestPalindrome("bb") << endl;
    return 0;
}
