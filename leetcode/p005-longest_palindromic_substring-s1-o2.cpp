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
SOLUTION 1 OPTIMIZATION 2 (DP, O(n) space):

Note that in Solution 1, each loop on 'len' only uses two columns, j and j-1. 
But there is a pitfall! We actually need 3 most recent columns to save the 
recent state, not two!

If you think only two different table reference are there in the inner loop so 
there should be O(2n) space used, you are wrong. To see this clearly, change 
the code a little bit. Notice that 'j' is not a loop variable. It is just 
converted from 'len' and 'i' for convenience. We actually can change all 'j' 
by an expression of 'i' and 'len'. Furthermore, we can think about the loops 
in terms of 'len' and 'i', and it is still (and even more) meaningful. See 
below:

    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        vector<vector<bool>> table(s.length(), vector<bool>(s.length()+1, false)); 
        int longest_length = 1, longest_i = 0;
        for (int len = 1; len <= s.size(); ++len) {
            for (int i = 0; i < s.size() - len + 1; ++i) { // note the termination condition
                if (len == 1) table[i][1] = true;
                else if (len == 2) {
                    if (s[i] == s[i+1]) {
                        table[i][2] = true;
                        if (2 > longest_length) {
                            longest_length = 2;
                            longest_i = i;
                        }
                    }
                } else {
                    if (s[i] == s[i+len-1] && table[i+1][len -2]) { // Notice here
                        table[i][len] = true;
                        if (len > longest_length) {
                            longest_length = len;
                            longest_i = i;
                        }
                    }
                }
            }
            
            
        }
        return s.substr(longest_i, longest_length);
    }

And it is actually a dynamic programming problem with a transfer function:

isPalindrome(i, len) = (s[i] == s[i+len-1] && isPalindrome(i+1)(len-2)),
isPalindrome(i, len) = true (when len==1)
isPalindrome(i, len) = (s[i] == s[i+1]) (when len==2)

And it is even clearer than using position i, j. The pitfall here is that 
'len' shifts one by one, but we really need the information of column 'len-2', 
which is two lines before 'len'. So we need 3 columns. The space is O(3n).

This is also because of that there are two basic conditions, len == 1 and 2, 
representing centers of odd and even length of palindromes.

To modify it as using O(3n) space, change the column into the first dimension. 
The vector solution will run within practical time but OJ gives TLE. 
Change it to plain array passes OJ.

    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        vector<vector<bool>> table(3, vector<bool>(s.length(), false)); 
        
        int longest_length = 1, longest_i = 0;
        for (int len = 1; len <= s.size(); ++len) {
            for (int i = 0; i < s.size() - len + 1; ++i) { // note the termination condition
                if (len == 1) table[2][i] = true;
                else if (len == 2) {
                    if (s[i] == s[i+1]) {
                        table[2][i] = true;
                        if (2 > longest_length) {
                            longest_length = 2;
                            longest_i = i;
                        }
                    }
                } else {
                    if (s[i] == s[i+len-1] && table[0][i+1]) {
                        table[2][i] = true;
                        if (len > longest_length) {
                            longest_length = len;
                            longest_i = i;
                        }
                    }
                }
            }
            table[0] = table[1];
            table[1] = table[2];
            table[2] = vector<bool>(s.length(), false);
        }
        return s.substr(longest_i, longest_length);
    }

Change it to using plain array. Use a rotational pointer index (len % 3) to 
avoid the harassment and overhead of switching rows. But still, remember to 
clear the row we are going to use in a loop of 'len'.


88 / 88 test cases passed.
Status: Accepted
Runtime: 465 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        bool table[3][1000];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < s.length(); ++j)
                table[i][j] = false;
        
        int longest_length = 1, longest_i = 0;
        for (int len = 1; len <= s.size(); ++len) {
            // clear the row we are going to use
            for (int j = 0; j < s.length(); ++j)
                table[(len % 3)][j] = false;

            for (int i = 0; i < s.size() - len + 1; ++i) { // note the termination condition
                if (len == 1) table[len % 3][i] = true;
                else if (len == 2) {
                    if (s[i] == s[i+1]) {
                        table[len % 3][i] = true;
                        if (2 > longest_length) {
                            longest_length = 2;
                            longest_i = i;
                        }
                    }
                } else {
                    if (s[i] == s[i+len-1] && table[(len - 2) % 3][i+1]) {
                        table[len % 3][i] = true;
                        if (len > longest_length) {
                            longest_length = len;
                            longest_i = i;
                        }
                    }
                }
            }
        }
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
