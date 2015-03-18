/*
21
Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/


Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


(EASY) Linked List
*/

/*
Solution 2, recursive

208 / 208 test cases passed.
Status: Accepted
Runtime: 16 ms
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
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
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