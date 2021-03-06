/*
28
Implement strStr() 
https://leetcode.com/problems/implement-strstr/


Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if 
needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of 
the pointer. If you still see your function signature returns a char * or 
String, please click the reload button  to reset your code definition.


(EASY) Two Pointers, String
*/

/*
It's easy to implement a brute-force algorithm, with a pitfall to exceed the 
time for special cases.
(Also, the special case when needle == '' needs to be considered.)

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i = 0;
        int len_needle = strlen(needle);
        if (len_needle == 0) return 0;
        while (*haystack != 0) {
            char *p1 = haystack;
            char *p2 = needle;
            for (; *p1 == *p2 && *p1 != 0 && *p2 != 0; p1++, p2++) {}
            if (*p2 == 0) return i;
            haystack++;
            i++;
        }
        return -1;
    }
};

When the 'needle' is very very long, and only mismatch at the end, it may still
running after the leftovers of haystack is shorter than needle, which is 
unnecessary.
To fix this, get the length of needle and if the leftover is shorter than this, 
terminate. 
Also note the boundary condition, to avoid failing in special cases such as 
"baa" vs. "aa", use (haystack+len_needle-1), not (haystack+len_needle), as the 
loop condition.

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i = 0;
        int len_needle = strlen(needle);
        if (len_needle == 0) return 0;
        while (*(haystack + len_needle - 1) != 0) {
            char *p1 = haystack;
            char *p2 = needle;
            for (; *p1 == *p2 && *p1 != 0 && *p2 != 0; p1++, p2++) {}
            if (*p2 == 0) return i;
            haystack++;
            i++;
        }
        return -1;
    }
};

Also note that there is a chance in the loop where we meet the end of the 
haystack first, when it is time to terminate the loop. In this case we don't 
need to modify the loop condition.
See solution below for this method. (Also note that the original loop condition 
is useless, where I put 'true' instead.)
Moreover, this solution has another advantage that we do not need to consider
the special case when needle=='', since the first loop is always executed. 
This cleans the code a bit more and we don't need strlen anymore.

72 / 72 test cases passed.
Status: Accepted
Runtime: 5 ms
*/

/* SOLUTION
O(nm) runtime, O(1) space – Brute force:

You could demonstrate to your interviewer that this problem can be solved using known efficient algorithms such as Rabin-Karp algorithm, KMP algorithm, and the Boyer- Moore algorithm. Since these algorithms are usually studied in an advanced algorithms class, it is sufficient to solve it using the most direct method in an interview – The brute force method.

The brute force method is straightforward to implement. We scan the needle with the haystack from its first position and start matching all subsequent letters one by one. If one of the letters does not match, we start over again with the next position in the haystack.

The key is to implement the solution cleanly without dealing with each edge case separately.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int i = 0;
        while (true) {
            char *p1 = haystack;
            char *p2 = needle;
            for (; *p1 == *p2 && *p1 != 0 && *p2 != 0; p1++, p2++) {}
            if (*p2 == 0) return i;
            if (*p1 == 0) return -1;
            haystack++;
            i++;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    char ch1[] = "interstellar";
    char ch2[] = "st";
    cout << solution.strStr(ch1, ch2) << endl;
    char ch3[] = "interstellar";
    char ch4[] = "star";
    cout << solution.strStr(ch3, ch4) << endl;
    char ch5[] = "";
    char ch6[] = "";
    cout << solution.strStr(ch5, ch6) << endl;
    char ch7[] = "aa";
    char ch8[] = "aa";
    cout << solution.strStr(ch7, ch8) << endl;
    char ch9[] = "baa";
    char ch10[] = "aa";
    cout << solution.strStr(ch9, ch10) << endl;
}
