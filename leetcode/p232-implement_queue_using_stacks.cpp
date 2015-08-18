/*
232
Implement Queue using Stacks
https://leetcode.com/problems/implement-queue-using-stacks/


Description:

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Notes:
You must use only standard operations of a stack -- which means only push to 
top, peek/pop from top, size, and is empty operations are valid.

Depending on your language, stack may not be supported natively. You may 
simulate a stack by using a list or deque (double-ended queue), as long as 
you use only standard operations of a stack.

You may assume that all operations are valid (for example, no pop or peek 
operations will be called on an empty queue).

(EASY) Stack, Data Structure
Similar Problems: 225 Implement Stack using Queues
*/

/*
SOLUTION: (Two-stack, O(n) for pushing)

Similar to using queues to simulate stacks, we use O(n) operation in 'push' to 
maintain the invariant that the first-come elements are on the top and the 
newest one is in the bottom.

The difference is that we will need another temporary stack to move all the 
elements into it, and then push the new one, and then move back all the old 
elements. Just imagine a stack of rings.

[5m]
17 / 17 test cases passed.
Status: Accepted
Runtime: 0 ms
*/


#include <iostream>
#include <stack>

using namespace std;

class Queue {
    stack<int> s, t;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.empty() << endl;
    q.pop();
    cout << q.peek() << endl;
    cout << q.empty() << endl;
    q.pop();
    cout << q.empty() << endl;
    
    return 0;
}
