/*
Using two stacks to implement a queue is simple. A stack follows LIFO
(Last In First Out), while a queue follows FIFO (First In First Out).

Idea:
Move all elements from S1 to S2, insert the new element into S1,
then move everything back from S2 to S1. This keeps the oldest
element at the top of S1, allowing the queue to behave as FIFO.

Initially:

S1          S2

| |         | |
| |         | |
| |         | |

Suppose S1 contains:
 
S1          S2

|3|         | |
|2|         | |
|1|         | |

Push(4)

Step 1: Move everything from S1 to S2.

S1          S2

| |         |1|
| |         |2|
| |         |3|

Step 2: Push the new element into S1.

S1          S2

|4|         |1|
            |2|
            |3|

Step 3: Move everything back from S2 to S1.

S1          S2

|1|         | |
|2|         | |
|3|         | |
|4|         | |

Now the oldest element (1) is on top of S1,
so pop() and peek() work exactly like a queue (FIFO).
*/

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
    }
    
    void push(int x) {
        // Move all elements from S1 to S2
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element
        s1.push(x);

        // Move everything back to S1
        while(s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();  // Return the front element
    }
    
    bool empty() {
        return s1.empty();  // Queue is empty if S1 is empty
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */