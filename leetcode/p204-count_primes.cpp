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
SOLUTION: Use a hash table to label the multiple of primes.

A bool vector is used as a hash table to label multiples of known primes from 
2, which can be inferred from the hash table. To avoid another loop to count 
the prime number, use a counter which increments when a cell turns to true.

The time complexity is O(n^2).

[15m]
20 / 20 test cases passed.
Status: Accepted
Runtime: 456 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> composite(n);
        int composite_counter = 0;
        for (int i = 2; i < n; ++i) {
            if (composite[i]) continue;
            for (int j = i * 2; j < n; j += i) {
                if (composite[j]) continue;
                composite[j] = true;
                composite_counter++;
            }
        }
        return n - composite_counter - 2;
    }
};

int main() {
    Solution solution;
    cout << solution.countPrimes(761551);
    
    return 0;
}
