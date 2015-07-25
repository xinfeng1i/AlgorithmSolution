#include "MyHeaders.h"

// Summary: use two stack to implement
//          make enqueue O(1) OR dequeue O(1)
class Queue 
{
public:
    // Push element x to the back of queue.
    void push(int x) 
    {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) 
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) 
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;

    }

    // Return whether the queue is empty.
    bool empty(void) 
    {
        return s1.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);  

    cout << "q.peek() = " << q.peek() << endl;
    cout << "q.empty() = " << q.empty() << endl;
    cout << "q.pop()" << endl;
    q.pop();

    cout << "q.peek() = " << q.peek() << endl;
    cout << "q.pop()" << endl;
    q.pop();

    q.push(4);


    cout << "q.peek() = " << q.peek() << endl;
    cout << "q.pop()" << endl;
    q.pop();

    cout << "q.peek() = " << q.peek() << endl;
    cout << "q.pop()" << endl;
    q.pop();

    cout << "q.empty() = " << q.empty() << endl;

    return 0;
}