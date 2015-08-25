/*
24
Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/


Description:

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in 
the list, only nodes itself can be changed.
 

(EASY) Linked List
Similar Problems: 25 (H) Reverse Nodes in k-Group
*/

/*
SOLUTION: (Linked List basics)

Use 3 pointers to do the swap for the current two nodes and maintain the third 
pointer to the next node.

Remember to consider corner cases, e.g., odd number of nodes.

[5m]
55 / 55 test cases passed.
Status: Accepted
Runtime: 4 ms
*/


#include <iostream>
#include <vector>
#include <string>

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
    struct ListNode* swapPairs(struct ListNode* head) {
        if (!head || !head->next) return head;
        struct ListNode * p1 = head;
        struct ListNode * p2 = head->next;
        struct ListNode * p3 = head->next->next;
        head = p2;
        while (true) {
            p2->next = p1;
            if (p3 && p3->next) {
                p1->next = p3->next;
            } else {
                p1->next = p3;
                break;
            }
            p1 = p3;
            if (p1) p2 = p1->next; else break;
            if (p2) p3 = p2->next; else break;
        }
        return head;
    }
};

int main() {
    Solution solution;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head = solution.swapPairs(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
