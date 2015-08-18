/*
237
Delete Node in a Linked List
https://leetcode.com/problems/delete-node-in-a-linked-list/


Description:

Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node 
with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

(EASY) Linked List
Similar Problems: 203 Remove Linked List Elements
*/

/*
SOLUTION: (Linked List Basics)

- For singly linked list, we cannot delete the current node directly, but can 
only replace this node's value with the next node's value, and delete the next 
node.

[3m+5m]
83 / 83 test cases passed.
Status: Accepted
Runtime: 16 ms
*/


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};

int main() {
    Solution solution;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    solution.deleteNode(head->next->next);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
