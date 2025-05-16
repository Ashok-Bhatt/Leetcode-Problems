class MyQueue {
private:
    stack<int> q1, q2;

public:
    MyQueue() {
        // Empty Constructor
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if (q2.empty()){
            while (!q1.empty()){
                q2.push(q1.top());
                q1.pop();
            }
        }

        int top = q2.top();
        q2.pop();
        return top;
    }
    
    int peek() {
        if (q2.empty()){
            while (!q1.empty()){
                q2.push(q1.top());
                q1.pop();
            }
        }

        return q2.top();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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