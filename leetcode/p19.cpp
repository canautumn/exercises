/*
19
Remove Nth Node From End of List 
https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/


Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

(EASY)  Linked List, Two Pointers
*/

/*
An intuitive way is to keep the latest n pointers in a line so that n pointers can 
be updated. Actually only 2 pointers are needed since a pointer can update itself
without keeping the pointers between two (leading and trailing) pointers.

Corner cases:
- Why we need to return a pointer? Because we may delete the head, in which case
we need to return a new head.

30m
207 / 207 test cases passed.
Status: Accepted
Runtime: 10 ms
*/


#include<iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;
 
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode * leading = head;
        ListNode * trailing = head;
        for (int i = 0; i < n; ++i) {
            leading = leading->next; // provided n is always valid
        }
        if (leading == NULL) { // n = size of the list, delete the head
            delete trailing;
            return head->next;
        }
        while (leading->next != NULL) { // leading is the last valid node
            leading = leading->next;
            trailing = trailing->next;
        }
        ListNode * temp = trailing->next->next;
        delete trailing->next;
        trailing->next = temp;
        
        return head;
    }
};

int main() {
    ListNode * head = new ListNode(1);
    ListNode * current = head;
    for (int i = 2; i <= 5; ++i) {
        current->next = new ListNode(i);
        current = current->next;
    }
    Solution solution;
    head = solution.removeNthFromEnd(head, 2);
    current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    ListNode *head2 = new ListNode(1);
    head2 = solution.removeNthFromEnd(head2, 1);
    current = head2;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
}
