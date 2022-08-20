class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
 
        int ans = 0, flag =1;
        while(flag) {
            flag = 0;
            for(int i = 0; i<n-1; i++){
                if(s[i]=='0' && s[i+1]=='1'){
                    flag=1;
                    swap(s[i],s[i+1]);
                    i++;
                }
            }
            ans+=flag;
        }
    
        return ans;
    }
};