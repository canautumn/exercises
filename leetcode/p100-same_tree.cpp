/*
88
Same Tree
https://leetcode.com/problems/same-tree/

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and 
the nodes have the same value.


(EASY) Tree, Depth-first Search
*/

/*
- Recursion is the easiest way to write DFS code. 
- The recursion end condition is that both of p, q are NULL. 
- If none of p or q is NULL, check the val and its sub trees. Note that the 
recursion call should be written at the end of the && conditions. Since the 
condition could have shortcut if the two values are not equal, such that the 
recursion to check the sub-trees are unnecessary. Of course the NULL check has 
to be at the beginning of the && conditions.
- Finally, the uncovered condition (including that only one of p, q is NULL) 
returns false.

The three if-conditions can be written in a one-liner:

    return (!p && !q) ? true : 
                        (p && q && p->val == q->val && 
                        isSameTree(p->left, q->left) && 
                        isSameTree(p->right, q->right)) ? true : false;

54 / 54 test cases passed.
Status: Accepted
Runtime: 3 ms
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (p && q && p->val == q->val && 
                      isSameTree(p->left, q->left) && 
                      isSameTree(p->right, q->right)) return true;
        return false;
    }
};

int main() {
    return 0; // no test cases here
}
