/*
101
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
Solution 2: BFS and using a NULL sentinel in the queue to mark the end of one 
level.

Using the same idea of solution 1, but simply put an additional NULL node when 
it is the end of one level so that it will know when to end a level when 
poping the nodes. (Also, when it knows a level ends when poping, it should 
push a new NULL into the queue.)

A pitfall: when a level ends, before it is going to push a NULL node into the 
queue, make sure to check that if the queue is empty, since if (not only the 
level ends but also) the tree ends, it should not push in a NULL node which 
will stop the while loop to terminate. Or, change the condition as below 
(while a new pitfall is introduced).

    while (!(q.size() == 1 && !q.front())) {
        TreeNode *v = q.front();
        q.pop();
        if (!v) {
            result.push_back(current_level);
            current_level.clear();
            q.push(NULL);
        } else {
            current_level.push_back(v->val);
            if (v->left) q.push(v->left);
            if (v->right) q.push(v->right);
        }
    }
    result.push_back(current_level);
    
        
34 / 34 test cases passed.
Status: Accepted
Runtime: 9 ms
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
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *v = q.front();
            q.pop();
            if (!v) {
                result.push_back(current_level);
                current_level.clear();
                if (!q.empty()) q.push(NULL);
            } else {
                current_level.push_back(v->val);
                if (v->left) q.push(v->left);
                if (v->right) q.push(v->right);
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
