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
SOLUTION 1: (Recursion, from two ends to center, each level checks for one pair)

(Naive solution is not discussed here.)

- To do it with O(n) time and without extra O(n) space, we can do the checking 
from two ends of the list to the center. However, we don't have backwards link 
since the list is singly linked list. 
- First we need one traversal to get the list length.
- If we recursively call a function to check the next symmetry "pair", and from 
the center, level by level, each recursive call returns the "next" pointer of 
the last node, we will be able to make use of that pointer in the upper level 
of recursion calls, to check the outer level pair of nodes.
- And if any of the pair is not equal, just return NULL to represent false. You 
can also do this by returning a bool, and use pass-by-reference to return the 
pointer.
- If returning a pointer like I did, take care of the outermost pair (the top 
level of the recursion), where the "next" pointer of the last node is always 
NULL. To avoid this ambiguous, add a sentinel node (on stack memory) at the end.
And remember to remove it.

- You may argue that the recursion uses O(n) space to store the status of each 
call (and it should not be a tailed recursion). However, this depends on how 
you define the question. You don't allocate O(n) additional space in your code. 
Anyway, for a real O(1) space solution, see SOLUTION 2.

[20m]
21 / 21 test cases passed.
Status: Accepted
Runtime: 28 ms
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
        int len = 1;
        ListNode sentinel(0);
        while (probe->next) {
            len++;
            probe = probe->next;
        }
        if (!probe->next) probe->next = &sentinel;
        ListNode * return_ptr = palindrome_traversal(head, len);
        if (return_ptr) {
            probe->next = NULL;
            return true;
        } else {
            probe->next = NULL;
            return false;
        }
    }
private:
    ListNode * palindrome_traversal(ListNode * head, int len) {
        if (len == 2) {
            if (head->val == head->next->val) return head->next->next;
            else return NULL;
        }
        if (len == 1) return head->next;
        ListNode * return_ptr = palindrome_traversal(head->next, len - 2);
        if (return_ptr) {
            if (head->val == return_ptr->val) return return_ptr->next;
            else return NULL;
        } else {
            return NULL;
        }
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
