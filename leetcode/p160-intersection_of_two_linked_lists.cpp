/*
160
Intersection of Two Linked Lists
https://leetcode.com/problems/intersection-of-two-linked-lists/


Write a program to find the node at which the intersection of two singly 
linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.

The linked lists must retain their original structure after the function 
returns.

You may assume there are no cycles anywhere in the entire linked structure.

Your code should preferably run in O(n) time and use only O(1) memory.

Credits:

Special thanks to @stellari for adding this problem and creating all test 
cases.


(EASY) Linked List
*/

/*
To use O(n) time and O(1) space, we can't compare the two list from the head. 
Since we don't know where the intersection happens without recording all the 
checked nodes to compare them. 

But if we think reversely, two intersected linked lists must be able to 
aligned from the end. Although we cannot iterate a linked list backwards, if 
we know the length of the linked lists, we can start from the shorter list's 
head, and the other list's corresponding node when it is aligned from the end 
of the shorter list. 

A couple of loops (passes) needed but the time is still O(n).

Note that trivial cases (NULL for any of the arguments) are automatically 
considered.

Alternatively, the last while loop can be written as below, since only this 
one condition also covers the case that they are both NULL, after which it 
will return NULL. The improvement is ignorable though.

    while (ptrLonger != ptrShorter) {
        ptrLonger = ptrLonger->next;
        ptrShorter = ptrShorter->next;
    }
    return ptrLonger;


[*]
42 / 42 test cases passed.
Status: Accepted
Runtime: 81 ms
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA) {
            ptrA = ptrA->next;
            lengthA++;
        }
        while (ptrB) {
            ptrB = ptrB->next;
            lengthB++;
        }
        int lengthDiff;
        ListNode *ptrLonger, *ptrShorter;
        if (lengthA < lengthB) {
            ptrLonger = headB;
            ptrShorter = headA;
            lengthDiff = lengthB - lengthA;
        } else {
            ptrLonger = headA;
            ptrShorter = headB;
            lengthDiff = lengthA - lengthB;
        }
        for (int i = 0; i < lengthDiff; ++i) ptrLonger = ptrLonger->next;
        while (ptrLonger) {
            if (ptrLonger == ptrShorter) return ptrLonger;
            ptrLonger = ptrLonger->next;
            ptrShorter = ptrShorter->next;
        }
        return NULL;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(10);
    l2->next = l1->next->next;
    
    Solution solution;
    ListNode *l3 = solution.getIntersectionNode(l1, l2);
    while (l3) {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;
    return 0;
}
