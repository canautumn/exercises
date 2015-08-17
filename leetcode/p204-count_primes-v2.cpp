/*
204
Count Primes
https://leetcode.com/problems/count-primes/


Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test 
cases.


(EASY) Hash Table, Math
Similar Problems: 
*/

/*
SOLUTION: Use a hash table to label the multiple of primes. (Variant)

An unordered_set is used as the hash_table to see whether the performance 
changes.

The time complexity is O(n^2).

Tips:
- unordered_set<T>'s T is the type of the key. So here it's int.

[15m]
20 / 20 test cases passed.
Status: Time Limit Exceeded
Runtime: (1.6s for 999983)
*/


#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        unordered_set<int> composite;
        for (int i = 2; i < n; ++i) {
            if (composite.find(i) != composite.end()) continue;
            for (int j = i * 2; j < n; j += i) {
                if (composite.find(j) != composite.end()) continue;
                composite.insert(j);
            }
        }
        return n - composite.size() - 2;
    }
};

int main() {
    Solution solution;
    cout << solution.countPrimes(999983);
    
    return 0;
}
