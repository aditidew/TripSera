#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;

public:
    MyQueue() {
        // nothing to initialize
    }

    // Push element to the back of queue
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue
    int pop() {
        if (s2.empty()) {
            // move everything from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    // Get the front element
    int peek() {
        if (s2.empty()) {
            // move everything from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Return whether the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
