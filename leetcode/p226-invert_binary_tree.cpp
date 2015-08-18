/*
226
Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/


Description:

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you 
can’t invert a binary tree on a whiteboard so fuck off.

(EASY) Tree
Similar Problems: 
*/

/*
SOLUTION: (Recursion)

Pitfalls:
- When swapping the left and right child, make sure to backup the second one. 

[1mx]
68 / 68 test cases passed.
Status: Accepted
Runtime: 0 ms
*/


#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode * right_backup = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(right_backup);
        return root;
    }
};

void post_order_traverse(TreeNode * root) {
    if (!root) return;
    post_order_traverse(root->left);
    post_order_traverse(root->right);
    cout << root->val << " ";
}

int main() {
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    Solution solution;
    root = solution.invertTree(root);
    
    post_order_traverse(root);
    return 0;
}
