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
Solution 1: BFS and keep track of the number of elements of current level and 
next level.

Level order traversal is simply BFS based on a queue. But to output the result 
level by level, we need to know when a level ends. This can be done by 
recording the number of elements of each level. When pushing one node in the 
queue, increase the count of the next level. When poping one node in the 
queue, decrease the count of the current level, and check that if it is zero, 
finish the output of current level and deal with the counts.

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
        int current_level_size = 1, next_level_size = 0;
        while (!q.empty()) {
            TreeNode *v = q.front();
            q.pop();
            current_level.push_back(v->val);
            current_level_size--;
            if (v->left) {
                q.push(v->left);
                next_level_size++;
            }
            if (v->right) {
                q.push(v->right);
                next_level_size++;
            }
            if (current_level_size == 0) {
                result.push_back(current_level);
                current_level.clear();
                current_level_size = next_level_size;
                next_level_size = 0;
            }
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
