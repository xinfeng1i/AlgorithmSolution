#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// using two queues to implement the stack
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1.pop();

        while (!q2.empty()) {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }

    }

    // Get the top element.
    int top() {
        while (q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }

        int ans = q1.front();
        q1.pop();
        q2.push(ans);

        while (!q2.empty()) {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }

        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};


int main() 
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.empty() << endl;
    return 0;
}
