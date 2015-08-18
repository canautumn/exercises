/*
206
Reverse Linked List 
https://leetcode.com/problems/reverse-linked-list/


Description:

Reverse a singly linked list.

Hint:
A linked list can be reversed either iteratively or recursively. Could you 
implement both?

(EASY) Linked List
Similar Problems: 92 Reverse Linked List II, 156 Binary Tree Upside Down, 
234 Palindrome Linked List
*/

/*
SOLUTION: (Recursion)

Tips:
- The returning value of the recursion is the last (newly first) node and it is 
passing back all the way along a tail recursion.
- Mind the special cases. 

[10m]
27 / 27 test cases passed.
Status: Accepted
Runtime: 8 ms
*/


#include <iostream>
#include <vector>

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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * prev = head;
        ListNode * curr = head->next;
        prev->next = NULL;
        return reverseList(curr, prev);
    }
private:
    ListNode* reverseList(ListNode* curr, ListNode* prev) {
        if (!curr) return prev;
        ListNode* next_backup = curr->next;
        curr->next = prev;
        return reverseList(next_backup, curr);
    }
};

int main() {
    Solution solution;
    vector<int> init_array {1, 2, 6, 3, 4, 5, 6};
    // vector<int> init_array {6};
    
    ListNode * test = new ListNode(init_array[0]);
    ListNode * iterator = test;
    for (int i = 1; i < init_array.size(); ++i) {
        iterator->next = new ListNode(init_array[i]);
        iterator = iterator->next;
    }
    test = solution.reverseList(test);
    while(test) {
        cout << test->val << " ";
        test = test->next;
    }
 
    return 0;
}
