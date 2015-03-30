/*
111
Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/


Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root 
node down to the nearest leaf node.


(EASY) Tree, Depth-first Search
*/

/*
Consider DFS recursion a simple solution. First think about the recursion 
terminating condition -- current node is a leaf, which means the node has both 
of its children NULL. It should return a number of depth of 1. This means we 
need to do both children's NULL checks in a recursion body. This means two 
things: 

1) We need to consider all four cases: both NULL, one of them NULL, and both 
not NULL. They should return different recursion result as below. 

2) We don't need to do the NULL check for the current node parameter in each 
recursion except for the initial 'root' node since we did that in the upper 
level recursion. So we can make a helper DFS function without do the NULL 
check to the node parameter, but only check the 'root' parameter ONCE in the 
main function -- the improvement is very much insignificant so we just leave 
the NULL check for the 'root' in each recursion function for clarity.

Consider a wrong solution below: the problem is that it wrongly implemented 
the condition of a leaf -- it takes min of two children of which one could be 
NULL and return 0, thus wrongly returned as if there was a leaf.
WRONG SOLUTION:
int minDepth(TreeNode *root) {
    if (!root) return 0;
    return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
}

41 / 41 test cases passed.
Status: Accepted
Runtime: 15 ms
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
    }
};

int main() {    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    cout << solution.minDepth(root) << endl;

    return 0;
}
