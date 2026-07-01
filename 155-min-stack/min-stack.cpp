/*
    I stored each element in the stack as a pair<int, int>.

    The first value stores the actual element, and the second value stores
    the minimum element in the stack up to that point, which I compute as
    min(currentValue, st.top().second).

    This way, I can always get the minimum element in O(1) time.
*/

class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value, value});
        } 
        else{
            st.push({value, min(value, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */