class MaxStack {
private:
    priority_queue<pair<int, int>> q;
    stack<pair<int, int>> s;
    unordered_set<int> removed;
    int count = 0;

public:
    MaxStack() {
        
    }
    
    void push(int x) {
        s.push({x, count});
        q.push({x, count});
        count++;
    }
    
    int pop() {
        while (removed.count(s.top().second))
            s.pop();
        pair<int, int> p = s.top();
        s.pop();
        removed.insert(p.second);
        return p.first;
    }
    
    int top() {
        while (removed.count(s.top().second))
            s.pop();
        return s.top().first;
    }
    
    int peekMax() {
        while (removed.count(q.top().second))
            q.pop();
        return q.top().first;
    }
    
    int popMax() {
        while (removed.count(q.top().second))
            q.pop();
        pair<int, int> p = q.top();
        q.pop();
        removed.insert(p.second);
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */