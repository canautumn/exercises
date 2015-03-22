/*
83
Remove Duplicates from Sorted List 
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given a sorted linked list, delete all duplicates such that each element 
appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


(EASY) Linked List
*/

/*
Use a current pointer as the "last" element, and compare current->next->val 
and current->val. Compare to Solution 1, this method is more concise. Since 
we check if current->next is NULL at the beginning of each loop, it is like 
checking the end of the list in advance, which is less error-prone and 
avoids an additional check for the end inside the loop.

164 / 164 test cases passed.
Status: Accepted
Runtime: 21 ms
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* current = head;
        while(current->next) {
            if (current->next->val == current->val) {
                ListNode* to_delete = current->next;
                current->next = current->next->next;
                delete to_delete;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;
    vector<int> l1data{1, 2, 3, 5, 5, 5, 7, 7, 9, 11};
    vector<int> l2data{2, 2};
    
    ListNode *l1 = new ListNode(l1data[0]);
    ListNode *current = l1;
    for (int i = 1; i < l1data.size(); ++i) {
        current->next = new ListNode(l1data[i]);
        current = current->next;
    }
    
    ListNode * result = solution.deleteDuplicates(l1);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    ListNode *l2 = new ListNode(l2data[0]);
    current = l2;
    for (int i = 1; i < l2data.size(); ++i) {
        current->next = new ListNode(l2data[i]);
        current = current->next;
    }
    
    result = solution.deleteDuplicates(l2);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
}
