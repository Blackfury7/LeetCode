class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i = 0; i < k-1; i++) {
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        
        int ans = 0;
        int flag = 1;
        for(int i = 1; i < n; i++) {
            if(flag < k) {
                if(colors[i] != colors[i-1]){
                    flag++;
                }
                else flag=1;
                continue;
            }
            if(flag==k) ans++;
            
            if(colors[i] == colors[i-1]){
                    flag=1;
                }
                
        }
        if(flag==k) ans++;
        return ans;
    }
};