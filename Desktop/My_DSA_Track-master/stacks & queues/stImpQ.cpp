#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    q.push(x);
    int size = q.size();

    // Rotate all elements except the newly inserted one
    for (int i = 0; i < size - 1; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if (q.empty()) {
        cout << "Stack Underflow\n";
        return;
    }
    q.pop();
}

int top() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q.front();
}

bool empty() {
    return q.empty();
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element: " << top() << endl;  // 30
    pop();
    cout << "Top element after pop: " << top() << endl;  // 20
    pop();
    cout << "Top element after pop: " << top() << endl;  // 10
    pop();
    pop();  // Underflow

    return 0;
}
