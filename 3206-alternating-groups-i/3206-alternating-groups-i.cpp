class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        int pre,next;
         for(int i =0; i < n; i++) {
             pre = i-1;
             next=i+1;
             if(pre<0) pre = n-1;
             next%=n;
             
             if(colors[i]!=colors[pre] and colors[i]!=colors[next]) ans++;
         }
        return ans;
    }
};