class Solution {
public:
    int strStr(string h, string n) {
        if(h.size() < n.size()) return -1;
        if(h.size() == n.size()) return h == n ? 0 : -1;
        for(int i=0;i<h.size()-n.size()+1;i++) {
            string h_part = "";
            for(int j=i;j<i+n.size();j++) {
                h_part += h[j];
            }
            if(h_part == n) return i;
        }
        return -1;
    }
};