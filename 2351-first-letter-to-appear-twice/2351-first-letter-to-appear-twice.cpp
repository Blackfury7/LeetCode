class Solution {
public:
    char repeatedCharacter(string s) {
        set<char>st;
        for(auto i:s){
            if(st.find(i) != st.end()){
                return i;
            }
            st.insert(i);
        }
        return 'a';
    }
};