class MinStack {
private:
    stack<int> elts;
    stack<int> smallest;

public:
    MinStack() {
        
    }
    
    void push(int val) { 
        elts.push(val);
        if (smallest.empty() or val <= smallest.top())
            smallest.push(val);
    }
    
    void pop() {
        int toPop = elts.top();
        elts.pop();
        if (toPop == smallest.top())
            smallest.pop();
    }
    
    int top() {
        return elts.top();
    }
    
    int getMin() {
        return smallest.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */