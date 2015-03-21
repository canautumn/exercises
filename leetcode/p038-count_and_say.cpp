/*
38
Count and Say 
https://leetcode.com/problems/count-and-say/


The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.


(EASY) String
*/

/*
Note that each element of the series depends on the previous element based on 
the "Count and Say" rule, and the question asks for the nth element. 
The idea is straight-forward once the question is understood. Since the result 
is based on the character counting, we only need to save the current result in 
a string and hand in for the next iteration. To save a little time 
initializing strings, we can use two strings to represent the nth result, 
depending on whether n is odd or even. Such as
    result[i % 2] is the current result; 
    result[(i + 1) % 2] is the next result.
So when i is increasing one by one, the result goes back and forth in the two 
strings. There are more optimization that can be done but may not worth doing.

18 / 18 test cases passed.
Status: Accepted
Runtime: 8 ms
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result[2] = {"", "1"};
        int i;
        int count;
        char last_c;
        for (i = 1; i < n; ++i) {
            result[(i + 1) % 2].clear();
            count = 0;
            last_c = 0;
            for (auto c : result[i % 2]) {
                count++;
                if (c != last_c) {
                    if (last_c != 0) {
                        result[(i + 1) % 2].append(to_string(count));
                        result[(i + 1) % 2].append(1, last_c);
                    }
                    count = 0;
                    last_c = c;
                }
            }
            if (last_c != 0) {
                result[(i + 1) % 2].append(to_string(count + 1));
                result[(i + 1) % 2].append(1, last_c);
            }
        }
        return result[i % 2];
    }
};

int main() {
    Solution solution;
    cout << solution.countAndSay(5) << endl;
}
