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
SOLUTION 2 (Expanding palindromes, O(n^2) time O(1) space):

There are 2n+1 possible palindrome center (for odd and even number of letters). 
So we can just check them. From each possible center of the palindrome, grow 
one letter by one letter on each side and check if they are the same, which 
takes O(n) time. The total time is O(n^2). Almost no additional space used.

Loop on the index of letters, for each iteration, check both the possible 
palindrome centered at that letter, and that between that letter and the next 
one. For each of the two cases, use a while loop, increasing length of the 
substring, and check both 1) if the index is out of range of the whole string; 
2) if the two side has different letter, to terminate the loop.

A personal opinion:

A pitfall is that the length the loop breaks is the first failing length, so 
make sure the longest palindrome length is updated semantically using the 
first failing length minus 1. Don't simplifies the equation as below since it 
adds a level of obscureness on the meaning of the program.

    'longest_i = i - (len - 1);' is better than 'longest_i = i - len + 1;'
    
Although both DP and this method has O(n^2) time complexity, this method is 6x 
faster than DP.


[*]
88 / 88 test cases passed.
Status: Accepted
Runtime: 81 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int longest_length = 1, longest_i = 0;
        for (int i = 0; i < s.length(); ++i) {
            int len = 1;
            while (i - len >= 0 && i + len < s.length()) {
                if (s[i - len] != s[i + len]) {
                    break;
                }
                len++;
            }
            int current_longest_length = (len - 1) * 2 + 1;
            if (longest_length < current_longest_length) {
                longest_length = current_longest_length;
                longest_i = i - (len - 1);
            }
                    
            len = 1;
            while (i - len + 1 >= 0 && i + len < s.length()) {
                if (s[i - len + 1] != s[i + len]) {

                    break;
                }
                len++;
            }
            current_longest_length = (len - 1) * 2;
            if (longest_length < current_longest_length) {
                longest_length = current_longest_length;
                longest_i = i - (len - 1) + 1;
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
