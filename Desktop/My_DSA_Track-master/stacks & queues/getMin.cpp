#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        while (!st.empty()) st.pop();
        mini = INT_MAX;
    }

    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long el = st.top();
        st.pop();
        if (el < mini) {
            mini = 2 * mini - el;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long el = st.top();
        if (el < mini) return mini;
        return el;
    }

    int getMin() {
        return mini;
    }
};

int main() {
    MinStack s;
    s.push(5);
    s.push(3);
    s.push(7);
    cout << s.getMin() << endl;  // Output: 3
    s.pop();
    cout << s.getMin() << endl;  // Output: 3
    s.pop();
    cout << s.top() << endl;     // Output: 5
    cout << s.getMin() << endl;  // Output: 5
    return 0;
}
