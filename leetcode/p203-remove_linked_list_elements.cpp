/*
203
Remove Linked List Elements
https://leetcode.com/problems/remove-linked-list-elements/


Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test 
cases.

(EASY) Linked List
Similar Problems: 27 Remove Element, 237 Delete Node in a Linked List
*/

/*
SOLUTION: Use a false-head to deal with special case with head.

Removing elements in a linked list requires maintaining two pointers, one to 
the current node, another to the previous node. To deal with the special case 
where the head could be removed, you can either do this before the loop, or use 
a 'false-head' before the head, since you don't need to worry about if the 
false-head could be removed.

[15mx]
63 / 63 test cases passed.
Status: Accepted
Runtime: 32 ms
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode false_head(0);
        false_head.next = head;
        ListNode * previous = &false_head;
        ListNode * probe = head;
        while (probe) {
            if (probe->val == val) {
                previous->next = probe->next;
                delete probe;
                probe = previous->next;
            } else {
                previous = probe;
                probe = probe->next;
            }
        }
        return false_head.next;
        // Note that the head pointer might not be changed if the head is 
        // removed. So here the returning should be the false-head's next node, 
        // which might be the second node if the head is removed. Also, the 
        // client code should be using the returning pointer, not the original 
        // head. Actually, this API prevents dealing with removing head 
        // correctly, since you cannot change 'head' pointer address like this:
        //      head = false_head.next; ( WRONG )
    }
};

int main() {
    Solution solution;
    // vector<int> init_array {1, 2, 6, 3, 4, 5, 6};
    vector<int> init_array {6};
    
    ListNode * test = new ListNode(init_array[0]);
    ListNode * iterator = test;
    for (int i = 1; i < init_array.size(); ++i) {
        iterator->next = new ListNode(init_array[i]);
        iterator = iterator->next;
    }
    test = solution.removeElements(test, 6);
    while(test) {
        cout << test->val << " ";
        test = test->next;
    }
    
    return 0;
}
