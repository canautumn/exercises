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
SOLUTION 1 OPTIMIZATION 2:

Solution 1 uses a vector of pair, recording each position and value of the min 
elements so that it checks if a min value is popped out when popping an 
element. Actually, there is a way to improve the space consumption. We don't 
need to record where the min element is. We simply pop the min value from the 
min stack if the popped element equals the min stack top. This requires 
dealing with multiple minima, just by also adding the element that equals to 
the current min stack top (minima). This guaranteed that if there are multiple 
same minima, popping one will not popping all of them.

So simply change the '<' to '<=' avoids recoding the index of the minima.

LEETCODE SOLUTION: 
Hints:
Consider space-time tradeoff. How would you keep track of the minimums using 
extra space?
Make sure to consider duplicate elements.
O(n) runtime, O(n) space – Extra stack:

Use an extra stack to keep track of the current minimum value. During the push 
operation we choose the new element or the current minimum, whichever that is 
smaller to push onto the min stack.

O(n) runtime, O(n) space – Minor space optimization:

If a new element is larger than the current minimum, we do not need to push it 
on to the min stack. When we perform the pop operation, check if the popped 
element is the same as the current minimum. If it is, pop it off the min stack 
too.

Submission Details
17 / 17 test cases passed.
Status: Accepted
Runtime: 75 ms
*/


#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    vector<int> stack_;
    vector<int> min_;
public:
    void push(int x) {
        if (stack_.empty()) {
            min_.push_back(x);
        } else {
            if (x <= min_.back()) min_.push_back(x);
        }
        stack_.push_back(x);
    }
    void pop() {
        if (!stack_.empty()) {
            if (stack_.back() == min_.back()) min_.pop_back();
            stack_.pop_back();
        }
    }
    int top() {
        return stack_.back();
    }

    int getMin() {
        return min_.back();
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
