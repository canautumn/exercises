/*
234
Palindrome Linked List 
https://leetcode.com/problems/palindrome-linked-list/


Description:

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

(EASY) Lined List, Two Pointers
Similar Problems: 9 Palindrome Number, 125 Valid Palindrome, 
206 Reverse Linked List
*/

/*
SOLUTION 2: (Reverse the second half of the linked list and compare 
the two halves)

- Refer to Problem 206 for reversing a singly linked list either by recursion 
or by iteration.
- Note that even using recursion for reversing the list, the recursion is a 
tailed recursion, in which case the space usage (even counting the recursion 
cost) can be considered as O(1).


[10m*]
21 / 21 test cases passed.
Status: Accepted
Runtime: 24-28 ms
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode * probe = head;
        int len = 0;
        while (probe) {
            len++;
            probe = probe->next;
        }
        probe = head;
        for (int i = 0; i < len / 2; ++i) {
            probe = probe->next;
        }
        if (len % 2) probe = probe->next;
        ListNode * probe2 = reverseList(probe);
        probe = head;
        for (int i = 0; i < len / 2; ++i) {
            if (probe->val != probe2->val) return false;
            probe = probe->next;
            probe2 = probe2->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * prev = head;
        ListNode * curr = head->next;
        ListNode * next = head->next->next;
        prev->next = NULL;
        while (next) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
};


int main() {
    Solution solution;
    ListNode * head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(3);
    
    cout << solution.isPalindrome(head) << endl;
    return 0;
}
