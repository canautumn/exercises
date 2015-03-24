/*
101
Symmetric Tree
https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric 
around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized 
on OJ (below):


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' 
signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".


(EASY) Tree, Depth-first Search
*/

/*


192 / 192 test cases passed.
Status: Accepted
Runtime: 7 ms
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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return checkSymmetry(root->left, root->right);
    }
    bool checkSymmetry(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (p && q && p->val == q->val && 
                      checkSymmetry(p->left, q->right) && 
                      checkSymmetry(p->right, q->left)) return true;
        return false;
    }
};

int main() {
    return 0; // no test cases here
}
