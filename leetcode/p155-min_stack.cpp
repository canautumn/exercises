/*
155
Min Stack 
https://lehttps://leetcode.com/problems/min-stack/


Design a stack that supports push, pop, top, and retrieving the minimum 
element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.


(EASY) Stack, Data Structure
*/

/*
SOLUTION 1: 
Use an extra internal stack to record each found minima's index and value. 
When the popping results in a shorter stack than the recorded latest minima's 
index, remove that minima. 

See SOLUTION 1 OPTIMIZATION 2. Using a small trick avoids recording the index 
of the minima.

Note that we have to assume the condition to call top() and getMin() is valid 
(non-empty stack) since there is no valid value they could return if the stack 
is empty. So the program doesn't check it, as a solution to the OJ.

Tips:
- std::stack uses 'deque' as its backend by default. This COULD be a little 
bit slower than using 'vector' in this simple case. So better use a 
std::vector-backended std::stack, or simply use std::vector.
- a vector's 'end()' returns a 'pass-the-end' iterator, not the iterator to 
the last element. Use 'back()' to get the value of the last element.
- std::pair has 'first' and 'second' public member variables but they are 
not functions. Don't put '()' after them.

17 / 17 test cases passed.
Status: Accepted
Runtime: 74 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    vector<int> stack_;
    vector<pair<int, int>> min_;
public:
    void push(int x) {
        if (stack_.empty()) {
            stack_.push_back(x);
            min_.push_back(make_pair(0, x));
        } else {
            stack_.push_back(x);
            if (x < min_.back().second) min_.push_back(make_pair(stack_.size() - 1, x));
        }
    }

    void pop() {
        if (stack_.size()) stack_.pop_back();
        if (stack_.size() <= min_.back().first) min_.pop_back();
    }

    int top() {
        return stack_.back();
    }

    int getMin() {
        return min_.back().second;
    }
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(2);
    minStack.push(5);
    minStack.push(1);
    minStack.pop();
    cout << minStack.top() << " " << minStack.getMin() << endl;

    return 0;
}
