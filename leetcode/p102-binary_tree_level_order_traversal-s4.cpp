/*
102
Binary Tree Level Order Traversal 
https://leetcode.com/problems/binary-tree-level-order-traversal/


Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized 
on OJ.


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


(EASY) Tree, Breadth-first Search
*/

/*
Solution 4: DFS, and keep a record of current level so that new nodes append 
only in the container indexed by the level number.

Because we need an additional argument to pass around the level number, a new 
DFS helper method is needed. The recursion terminating condition is the node 
is NULL (so root NULL detection is not necessary). Also, when a level is first 
met, a new vector needs to append to the result container.

DFS recursion method doesn't need queue and is more concise. It makes uses of 
the fact that we can come back to a level to record a new node's value using 
the level number indexed container, so that we don't need to really traverse 
the tree by level order.

34 / 34 test cases passed.
Status: Accepted
Runtime: 8 ms
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
    vector<vector<int>> result;
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        levelOrderDFS(root, 0);
        return result;
    }
    void levelOrderDFS(TreeNode* node, int level) {
        if (!node) return;
        if (level == result.size()) result.push_back(vector<int>());
        result[level].push_back(node->val);
        levelOrderDFS(node->left, level + 1);
        levelOrderDFS(node->right, level + 1);
    }
};

int main() {    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    
    return 0;
}
