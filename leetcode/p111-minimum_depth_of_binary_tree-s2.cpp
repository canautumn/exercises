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
SOLUTION 2: BFS and terminate if a leaf is found at a certain level.

Using BFS to do level traversal is also a natural solution. Since we need to 
count the depth, we can do a level traversal using BFS and track the queue 
size or other method, to track whether a level is done, at which time we need 
to update the level counter. So it is based on Problem 102 Binary Tree Level 
Order Traversal, with the addition that it should terminate the loop when one 
node is a leaf in the current level.

The level order traversal solution also has an advantage over DFS recursion in 
the cases that the tree is significant unbalanced -- it terminates as soon as 
it finds a leaf in a level without traveling down, not like DFS which is 
traveling down to every leaves anyway. But it doesn't have too much advantages 
in the common cases.

The solution below is based on Problem 102 Solution 1. Similar solutions based 
on other solutions of Problem 102 is possible.


41 / 41 test cases passed.
Status: Accepted
Runtime: 14 ms
*/

#include <iostream>
#include <queue>

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
        queue<TreeNode*> q;
        q.push(root);
        int current_level_size = 1, next_level_size = 0, result = 1;
        while (!q.empty()) {
            TreeNode *v = q.front();
            q.pop();
            current_level_size--;
            if (!v->left && !v->right) break;
            if (v->left) {
                q.push(v->left);
                next_level_size++;
            }
            if (v->right) {
                q.push(v->right);
                next_level_size++;
            }
            if (current_level_size == 0) {
                current_level_size = next_level_size;
                next_level_size = 0;
                result++;
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
    cout << solution.minDepth(root) << endl;

    return 0;
}
