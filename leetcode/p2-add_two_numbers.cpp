/*
2
Add Two Numbers
https://leetcode.com/problems/add-two-numbers/


You are given two linked lists representing two non-negative numbers. The 
digits are stored in reverse order and each of their nodes contain a single 
digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


(MEDIUM) Linked List, Math
*/

/*
Linked list and dealing with carry digits.

Think about various edge cases, such as l1 is longer, l2 is longer, carry 
digit propagates through a series of 9's, etc.

Note that all three cases (l1 is longer, l2 is longer, or same length) can use 
the same carry number processing loop (See 'while(carry)') with soem 
preprocessing before that, and that will be only one additional step if we are 
allowed to modify the original linked lists:

If we are adding l2 onto l1, only if l2 is longer, concatenate the leftovers 
of l2 to the end of l1 when l1 ends. Then we can go on processing carry digits 
and the (possibly) left over of l1.

Note that it is natural to use 'node' NULL check in the iteration instead of 
'node->next' NULL check, in which way the previous node is not kept. However, 
we will use the previous node to concatenate possible leftovers of l2, or 
create additional carry digits. So we can either change the paradigm to loop 
on 'node->next', or simply keep a copy of previous l1 node.

More words: initially it is straightforward to process three cases separately, 
and later it could be noticed that the case l1, l2 having the same length can 
be combined to the second while loop, to make it more concise without any loss. 



[20m+]
1555 / 1555 test cases passed.
Status: Accepted
Runtime: 58 ms
*/


#include <iostream>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = l1, *l1_prev = 0;
        int carry = 0;
        while (l1 && l2) {
            l1->val += l2->val + carry;
            carry = l1->val / 10;
            l1->val %= 10;
            l1_prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) {
            l1_prev->next = l2;
        }
        
        while (carry) {
            if (!l1_prev->next) {
                l1_prev->next = new ListNode(carry);
                break;
            }
            l1_prev->next->val += carry;
            carry = l1_prev->next->val / 10;
            l1_prev->next->val %= 10;
            l1_prev = l1_prev->next;
        }
        return result;
    }
};

int main() {
    Solution solution;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(1);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(9);
    ListNode *r = solution.addTwoNumbers(l1, l2);
    // ListNode *l2 = new ListNode(1);
    // ListNode *l1 = new ListNode(9);
    // l1->next = new ListNode(9);
    // ListNode *r = solution.addTwoNumbers(l1, l2);
    while (r) {
        cout << r->val << (r->next ? " -> " : ""); // parentheses required
        r = r->next;
    }
    cout << endl;
    return 0;
}
