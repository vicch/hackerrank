// Problem:
// Implement a queue with two stacks.
// 
// Solution:
// Use one stack s1 for pushing, the other one s1 for poping. Pop all elements
// from s1 and push into s2 when poping or peeking from queue and s2 is empty.

class MyQueue {
public:
    stack<int> s1, s2;

    void push(int x) {
        s1.push(x);
        return;
    }

    void pop() {
        if (s2.empty()) swap();
        s2.pop();
        return;
    }

    int front() {
        if (s2.empty()) swap();
        return s2.top();
    }

protected:
    void swap() {
        while (!s1.empty())
            s2.push(s1.top()), s1.pop();
        return;
    }
};