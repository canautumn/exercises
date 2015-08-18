/*
235
Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


Description:

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two 
given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
defined between two nodes v and w as the lowest node in T that has both v and w 
as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another 
example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of 
itself according to the LCA definition.

(EASY) Tree
Similar Problems: 236 Lowest Common Ancestor of a Binary Tree
*/

/*
SOLUTION: (Reverse the second half of the linked list and compare 
the two halves)

- A BST has the property that all the descent nodes on the left branch are 
smaller than the root, and all the descent nodes on the left branch are larger 
than the root.
- So there are two cases: if the two given node is on the two side of the root 
(or the current node, recursively), then the root is the LCA. Otherwise we can 
recursively repeat this process, on the correct side of the branch.
- If a NULL node is reached, then the specified node is not in the tree. 

[10m]
27 / 27 test cases passed.
Status: Accepted
Runtime: 40 ms
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if ((root->val >= p->val && root->val <= q->val) || 
            (root->val <= p->val && root->val >= q->val)) {
            return root;
        }
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return lowestCommonAncestor(root->right, p, q);
    }
};

int main() {
    Solution solution;
    TreeNode * root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    cout << solution.lowestCommonAncestor(root, root->left, root->left->right)->val << endl;
    return 0;
}
