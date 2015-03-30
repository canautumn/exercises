/*
110
Balanced Binary Tree
https://leetcode.com/problems/balanced-binary-tree/


Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.


(EASY) Tree, Depth-first Search
*/

/*
Consider using DFS with recursion. What we need to return for each level of 
recursion? First we need to return if the subtrees of this level are balanced 
or not. But to get that information, we need information that more than one 
level. Thus secondly we need to pass the max depth of each node's subtrees, 
such that we can compare them in a higher level. To return both of these 
values, we can use -1 to represent 'false' (not balanced) and once a recursion 
returns -1, -1 will be passed all the way up to the root and no need to 
compare the super nodes. Otherwise the depth of subtrees should be compared in 
each level.

226 / 226 test cases passed.
Status: Accepted
Runtime: 19 ms
*/

#include <iostream>
#include <vector>

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
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (isBalancedDFS(root) == -1) return false;
        return true;
    }
    int isBalancedDFS(TreeNode *node) {
        int depth_left = node->left ? isBalancedDFS(node->left) : 0;
        int depth_right = node->right ? isBalancedDFS(node->right) : 0;
        if (depth_left == -1 || depth_right == -1 || 
            depth_left - depth_right < -1 || 
            depth_left - depth_right > 1) return -1;
        return (max(depth_left, depth_right)) + 1;
    }
};

int main() {    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    cout << solution.isBalanced(root) << endl;

    return 0;
}
