class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> grp_stack;
    
    int mx_freq = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mx_freq = max(mx_freq,freq[val]);
        grp_stack[freq[val]].push(val);
    }
    
    int pop() {
        int top_mx_freq = grp_stack[mx_freq].top();
        
        grp_stack[mx_freq].pop();
        freq[top_mx_freq]--;
        
        if(grp_stack[mx_freq].size() == 0)
            mx_freq--;
        
        return top_mx_freq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */