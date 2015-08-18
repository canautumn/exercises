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
SOLUTION 2: (Iteration)

Use a stack to simulate call stack of a recursion. First, push the "parameter" 
(root) into the stack. Then for each iteration: 

1. Pop the top into a pointer (pop() usually comes with top(), especially when 
simulating a call stack. Either case (end of "recursion", or not) the current 
to-be-processing element should be popped and checked.)
2. Check the node, if it is NULL, "return" or going to the next iteration to 
check the next element on the stack.
3. If not NULL, swap the left and right child of the node, and push the two 
child onto the stack. (Simulating two calls with the parameters of the two 
childs.)
4. Loop until the stack is empty.

[20m]
68 / 68 test cases passed.
Status: Accepted
Runtime: 0 ms
*/


#include <iostream>
#include <stack>

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
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode * probe = s.top();
            s.pop();
            if (!probe) continue;
            swap(probe->left, probe->right);
            s.push(probe->left);
            s.push(probe->right);
        }
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
