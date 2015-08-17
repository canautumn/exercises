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
SOLUTION: Check prime by checking if divisible by numbers less than sqrt(n).

The time complexity is O(n^2).

[*]
20 / 20 test cases passed.
Status: Time Limit Exceeded
Runtime: (0.8s for 1500000)
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (isPrime(i)) count++;
        }
        return count;
    }
private:
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.countPrimes(1500000);
    
    return 0;
}
