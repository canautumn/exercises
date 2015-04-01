/*
112
Path Sum
https://leetcode.com/problems/path-sum/


Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


(EASY) Tree, Depth-first Search
*/

/*
This problem is very similar to Problem 111: Minimum Depth of Binary Tree. 
They both require checking both of the two children of each node to verify 
whether a node is a leaf or not, in which case the NULL check happens in the 
upper level of a node, not 'simply' the current level of node.

This is an important character of this type of problems. If we do not do the 
NULL check in the upper level, there is no way to determine whether a node is 
a leaf, thus leading to a wrong solution (failure to determine a leaf node) as 
follows:

WRONG SOLUTION:
bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return sum ? false : true;
    return hasPathSum(root->left, sum - root->val) || 
           hasPathSum(root->right, sum - root->val);
}

But there is also a difference to Problem 111. In Problem 111, we need to 
consider when two of the children have one of them NULL, and another not NULL. 
If we directly copy the solution to Problem 111 and write the solution as 
below:

SOLUTION (VERBOSE):
bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return sum - root->val ? false : true;
    if (!root->left) return hasPathSum(root->right, sum - root->val);
    if (!root->right) return hasPathSum(root->left, sum - root->val);
    return hasPathSum(root->left, sum - root->val) || 
           hasPathSum(root->right, sum - root->val);
}

Line 3,4 of the function is actually not necessary. In Problem 111, we need to 
count every possible down path's depth so we need to cover these two 
conditions (and the root NULL check is not necessary except for the first 
one). In this problem, we simply need a bool result for each of them, which 
can be obtained from Line 1, the current node NULL check. So Line 3,4 can be 
simply removed. (And this improves the performance, approx. 20ms to 16ms.) The 
key here Problem 111 cannot be written as this is because that it requires min 
value of the children's path, but 'no child' on one of the branch simply 
cannot count as the end of a path, otherwise the path terminates too early at 
a node that has one subtree.

Therefore, even similar problem has their own different cases to apply 
different rules.


114 / 114 test cases passed.
Status: Accepted
Runtime: 16 ms
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return sum - root->val ? false : true;
        return hasPathSum(root->left, sum - root->val) || 
               hasPathSum(root->right, sum - root->val);
    }
};

int main() {    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    cout << solution.hasPathSum(root, 12) << endl;

    return 0;
}
