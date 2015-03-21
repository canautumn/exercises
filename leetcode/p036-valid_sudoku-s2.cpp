/*
36
Valid Sudoku
https://leetcode.com/problems/valid-sudoku/


Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with 
the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the 
filled cells need to be validated.


(EASY) Hash Table
*/

/*
Use the similar idea, but use a flags array (one flag for each number and each 
row / column / block) to quickly check if a number exists on the board. 
This is much faster than the unordered_set solution.

501 / 501 test cases passed.
Status: Accepted
Runtime: 14 ms
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        bool inRow[9][9] = {0}, inCol[9][9] = {0}, inBlock[9][9] = {0};
        for(int i = 0; i < 9; ++ i)
            for(int j = 0; j < 9; ++ j)
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
                    if (inRow[i][num] || inCol[j][num] || inBlock[k][num])
                        return false;
                    inRow[i][num] = inCol[j][num] = inBlock[k][num] = true;
                }
        return true;
    }
};

int main() {
    Solution solution;
    string s[9] = {"53..7....", "6..195...", ".98....6.", 
                   "8...6...3", "4..8.3..1", "7...2...6", 
                   ".6....28.", "...419..5", "....8..79"};
    vector<vector<char> > board = {{s[0].begin(), s[0].end()}, 
                                   {s[1].begin(), s[1].end()}, 
                                   {s[2].begin(), s[2].end()}, 
                                   {s[3].begin(), s[3].end()}, 
                                   {s[4].begin(), s[4].end()}, 
                                   {s[5].begin(), s[5].end()}, 
                                   {s[6].begin(), s[6].end()}, 
                                   {s[7].begin(), s[7].end()}, 
                                   {s[8].begin(), s[8].end()}};
    cout << solution.isValidSudoku(board) << endl;
    
    string s2[9] = {"....5..1.",".4.3.....",".....3..1",
                   "8......2.","..2.7....",".15......",
                   ".....2...",".2.9.....","..4......"};
    vector<vector<char> > board2 = {{s2[0].begin(), s2[0].end()}, 
                                   {s2[1].begin(), s2[1].end()}, 
                                   {s2[2].begin(), s2[2].end()}, 
                                   {s2[3].begin(), s2[3].end()}, 
                                   {s2[4].begin(), s2[4].end()}, 
                                   {s2[5].begin(), s2[5].end()}, 
                                   {s2[6].begin(), s2[6].end()}, 
                                   {s2[7].begin(), s2[7].end()}, 
                                   {s2[8].begin(), s2[8].end()}};
    cout << solution.isValidSudoku(board2) << endl;
}
