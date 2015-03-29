/*
107
Binary Tree Level Order Traversal II 
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/


Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]


(EASY) Tree, Breadth-first Search
*/

/*
Use the same methods in '102: Binary tree level order traversal' and reverse 
the result container at the end. Other solutions are not repeated.

34 / 34 test cases passed.
Status: Accepted
Runtime: 9 ms
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> current_level;
        queue<TreeNode*> q;
        q.push(root);
        int current_level_size = 1, next_level_size = 0;
        while (!q.empty()) {
            TreeNode *v = q.front();
            q.pop();
            current_level.push_back(v->val);
            current_level_size--;
            if (v->left) {
                q.push(v->left);
                next_level_size++;
            }
            if (v->right) {
                q.push(v->right);
                next_level_size++;
            }
            if (current_level_size == 0) {
                result.push_back(current_level);
                current_level.clear();
                current_level_size = next_level_size;
                next_level_size = 0;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    vector<vector<int>> result = solution.levelOrderBottom(root);
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
