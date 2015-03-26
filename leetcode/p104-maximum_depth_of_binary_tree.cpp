/*
104
Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/


Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root 
node down to the farthest leaf node.




(EASY) Tree, Depth-first Search
*/

/*
DFS, using recursion, the current level count is the max (not sum) of the two 
children's maxDepth plus 1. NULL (leaves' children, or NULL root) returns 0 
(also the termination of recursion).

38 / 38 test cases passed.
Status: Accepted
Runtime: 13 ms
*/

#include <iostream>

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
    int maxDepth(TreeNode *root) {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    cout << solution.maxDepth(root) << endl;
    return 0;
}
