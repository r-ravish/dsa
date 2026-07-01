/*
Using a queue to implement a stack is simple. Push the new element into the
queue, then move all previously existing elements from the front to the back.
This brings the newly inserted element to the front, making it behave like
the top of a stack (LIFO).

Consider an empty queue

// Push 4
|4|

// Push 2
|4|2|

The problem is q.front() returns 4, but in a stack (LIFO) the top should be 2.
So, move the previous elements from the front to the back until the newly
inserted element reaches the front.

Hence the queue becomes -> |2|4| and the front returns 2
*/

class MyStack {
public:
    queue<int> q;
    int s;

    MyStack() {
    }
    
    void push(int x) {
        s = q.size();
        q.push(x);

        for(int i = 1; i <= s; i++) {  //Move all previous elements behind the new element
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();  // Front of the queue represents the top of the stack
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();  // Return the current top element
        
    }
    
    bool empty() {
        return q.empty();  // Stack is empty if the queue is empty
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */