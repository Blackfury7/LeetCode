class Solution {
public:
    vector<string> ans;
    void gen(string &s, int open, int close){
        if(open ==0 and close ==0){
            ans.push_back(s);
            return;
        }
        if(open > 0) {
            s.push_back('(');
            gen(s, open - 1, close);
            // backtracking step
            s.pop_back();
        }
        if(close > 0 and open < close)//it means opened brackets should be more than closed ones
        {
            s.push_back(')');
            gen(s, open, close - 1);
            //backtracking step
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        gen(s,n,n);
        return ans;
    }
};