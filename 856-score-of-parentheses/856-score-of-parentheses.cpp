class Solution {
public:
    
    int scoreOfParentheses(string s) {
       int depth = 0, score = 0;
        char prev = '(';
        
        for (const char &c: s) {
            if (c == '(')
                depth++;
             else {
                depth--;
                if (prev == '(')
                    score += 1<<depth;
            }
            
            prev = c;
        }
        
        return score;
    }
};