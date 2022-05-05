class MyStack {
public:
    
    queue<int>  q;
    int peek =-1;
    MyStack() {
        
    }
    
    void push(int x) {
        peek = x;
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        n -= 1;
        while(n--){
            peek = q.front();
            q.push(peek);
            q.pop();
        }
        
        int ret = q.front();
        q.pop();
        
        return ret;
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        return q.size() == 0;
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