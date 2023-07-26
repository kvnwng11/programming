class MyQueue {
private:
    stack<int> elts;
    stack<int> rev;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!rev.empty()) {
            elts.push(rev.top());
            rev.pop();
        }
        elts.push(x);
    }
    
    int pop() {
        while (!elts.empty()) {
            rev.push(elts.top());
            elts.pop();
        }
        int ans = rev.top();
        rev.pop();
        return ans;
    }
    
    int peek() {
        while (!elts.empty()) {
            rev.push(elts.top());
            elts.pop();
        }
        return rev.top();
    }
    
    bool empty() {
        return elts.empty() and rev.empty();
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