/*
21
Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/


Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


(EASY) Linked List
*/

/*
Don't be confused with "!ptr" and "ptr"

208 / 208 test cases passed.
Status: Accepted
Runtime: 15 ms
*/

#include <iostream>
#include <vector>

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *result = NULL, *current = NULL;
        if (!l1 && !l2) return NULL;
        if (!l1 && l2) return l2;
        if (l1 && !l2) return l1;
        if (l1->val < l2->val) {
            result = l1;
            l1 = l1 -> next;
        } else {
            result = l2;
            l2 = l2 -> next;
        }
        current = result;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) {
            current->next = l1;
        } else {
            current->next = l2;
        }
        return result;
    }
};

int main() {
    vector<int> l1data{1, 2, 3, 4, 5, 6, 7, 7, 9, 11};
    vector<int> l2data{2, 4, 4, 5, 7, 8, 9, 10};
    
    ListNode *l1 = new ListNode(l1data[0]);
    ListNode *current = l1;
    for (int i = 1; i < l1data.size(); ++i) {
        current->next = new ListNode(l1data[i]);
        current = current->next;
    }
    
    ListNode *l2 = new ListNode(l2data[0]);
    current = l2;
    for (int i = 1; i < l2data.size(); ++i) {
        current->next = new ListNode(l2data[i]);
        current = current->next;
    }
    
    Solution solution;
    ListNode *result = solution.mergeTwoLists(l1, l2);
    current = result;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
}