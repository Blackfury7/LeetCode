class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, j = 0;
        while(j < n) {
            int cnt = 0;
            char curr = chars[j];
            while(j<n && chars[j]==curr) {
                cnt++;
                j++;
            }
            chars[i++] = curr;
            if(cnt > 1) {
                string c = to_string(cnt);
                int pos = 0;
                while(pos<c.size()) chars[i++] = c[pos++];
            }
            if(j == n) break;
        }
        return i;
    }
};