/*
118
Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/


Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]


(EASY) Array
*/

/*
Generate the Pascal's Triangle by successive equation. Make sure to check the 
edge condition when numRows = 0 (still valid input) in which case it should 
return an empty vector.

In the solution below, the initial 1's on two side of the array is generated 
using initialization, which makes the code a little cleaner.
SOLUTION (ALTERNATIVE)
vector<vector<int> > generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0) return result;
    for (int i = 1; i <= numRows; ++i) {
        vector<int> row(i, 1);
        for (int j = 1; j < i - 1; ++j) 
            row[j] = result[i-2][j-1] + result[i-2][j];
        result.push_back(row);
    }
    return result;
}

15 / 15 test cases passed.
Status: Accepted
Runtime: 3 ms
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) return result;
        result.push_back(vector<int> {1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i; ++j) {
                row.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> result;
    Solution solution;
    result = solution.generate(5);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
