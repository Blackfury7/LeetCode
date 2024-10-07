class Solution {
public:
    int minLength(string s) {
        stack<int> stk;
        for(auto c: s){
            if(c == 'B' && stk.size() && stk.top() == 'A') stk.pop();
            else if(c == 'D' && stk.size() && stk.top() == 'C') stk.pop();
            else stk.push(c);
        }
        return stk.size();
    }
};