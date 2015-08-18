/*
257
Binary Tree Paths
https://leetcode.com/problems/binary-tree-paths/


Description:

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all 
test cases.


(EASY) Tree, Depth-first Search
Similar Problems: 113 Path Sum II
*/

/*
SOLUTION: (DFS with additional maintenance)

Tips:
- This is a DFS problem. 
- The idea is to maintain a path to current node. This path can only store the 
node values on the path since we only need to output the values. 
- You can do it either recursively or iteratively. For recursion, you can pass 
the current path by reference or use a member variable. For iteration, it is 
more obvious. 
- Here the iteration is used and a vector is used to store the path.
- We need to maintain a correct length of path vector according to the current 
level of the traversal. For recursion, you can passing the level by a parameter. 
For iteration, you can passing the level along with the node on the stack. 
- Here a pair is used to pairing node and level number to store the correct 
level number.

Pitfalls:
- In this problem we need to consider the case where a node is a leaf (both two 
children are NULL), and for non-leaf node, we need to consider whether one of 
the children is NULL. So there are basically 1 (both NULL) + 3 (one or no NULL) 
cases. Whether we need to check the children's nullability depends on problems.

[10m+3mx]
209 / 209 test cases passed.
Status: Accepted
Runtime: 4 ms
*/


#include <iostream>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        vector<int> path;
        stack< pair<TreeNode*, int> > s;
        s.push(make_pair(root, 0));
        while (!s.empty()) {
            int level = s.top().second;
            path.resize(level);
            TreeNode * node = s.top().first;
            s.pop();
            path.push_back(node->val);
            if (!node->left && !node->right) {
                string pathstr;
                for (int i = 0; i < path.size(); ++i) {
                    pathstr += to_string(path[i]) + ((i != path.size() - 1) ? "->" : "");
                }
                result.push_back(pathstr);
            } else {
                // Need to check nullability
                if (node->right) s.push(make_pair(node->right, level + 1));
                if (node->left) s.push(make_pair(node->left, level + 1));
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
 
    for (auto s : solution.binaryTreePaths(root)) {
        cout << s << endl;
    }
 
    return 0;
}
