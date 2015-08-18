/*
225
Implement Stack using Queues
https://leetcode.com/problems/implement-stack-using-queues/


Description:

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to 
back, peek/pop from front, size, and is empty operations are valid.

Depending on your language, queue may not be supported natively. You may 
simulate a queue by using a list or deque (double-ended queue), as long as you 
use only standard operations of a queue.

You may assume that all operations are valid (for example, no pop or top 
operations will be called on an empty stack).

Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of 
Stack.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test 
cases.

(EASY) Stack, Data Structure
Similar Problems: 232 Implement Queue using Stacks
*/

/*
SOLUTION: 

When pushing the element, iteratively dequeue the front element n - 1 times. 
So every time it is as if the new element is put directly in the front. 

The time complexity of push is O(n). 

[8m]
16 / 16 test cases passed.
Status: Accepted
Runtime: 0 ms
*/


#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            int e = q.front();
            q.pop();
            q.push(e);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "empty? " << s.empty() << endl;
    s.pop();
    cout << "empty? " << s.empty() << endl;
    return 0;
}
