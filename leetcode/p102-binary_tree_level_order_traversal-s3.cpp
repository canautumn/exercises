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
Solution 3: BFS and add another loop for each level, with recording the size 
of the queue before entering a new level.

Another structure to organize the problem is to use two loops for both levels 
and elements, and before entering a new level, we know how many elements of 
the level so that we know how many times to pop the queue, even there will be 
more elements pushed into the queue.

34 / 34 test cases passed.
Status: Accepted
Runtime: 8 ms
*/

#include <iostream>
#include <queue>
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> current_level;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int current_level_elements = q.size();
            for (int i = 0; i < current_level_elements; ++i) {
                TreeNode *v = q.front();
                q.pop();
                current_level.push_back(v->val);
                if (v->left) q.push(v->left);
                if (v->right) q.push(v->right);
            }
            result.push_back(current_level);
            current_level.clear();
        }
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
    vector<vector<int>> result = solution.levelOrder(root);
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    
    return 0;
}
