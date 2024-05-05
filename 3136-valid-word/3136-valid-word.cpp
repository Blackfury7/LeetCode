class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;
        string s = "@#$";
        string v = "aeiouAEIOU";
        int vo=0;
        int cons =0;
        for(auto &i: word) {
            if(i == '@' or i=='#' or i=='$') {
                return false;
            }
            if(('a' <= i and i <= 'z') or ('A' <= i and i<= 'Z') ){
                int flag = 0;
                for(auto &j: v){
                    if(i == j){
                        vo = 1;
                        flag = 1;
                    }
                }
                    if(!flag){
                        cons = 1;
                }
            }
        }
        return vo+cons == 2;
    }
};