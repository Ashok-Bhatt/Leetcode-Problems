class MyQueue {
private:
    stack<int> q;

public:
    MyQueue() {
        // Empty Constructor
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int top = q.top();
        q.pop();

        if (q.size() == 0){
            return top;
        } else {
            int ans = pop();
            q.push(top);
            return ans;
        }
    }
    
    int peek() {
        int top = q.top();
        q.pop();

        if (q.size() == 0){
            q.push(top);
            return top;
        } else {
            int ans = peek();
            q.push(top);
            return ans;
        }
    }
    
    bool empty() {
        return q.size()==0;
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