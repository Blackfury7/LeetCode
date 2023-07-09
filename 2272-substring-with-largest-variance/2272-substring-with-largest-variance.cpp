class Solution {
public:
    int largestVariance(string s) {
        vector<int> frq(26,0);
        int ans=0;
        for(auto it:s){
            frq[it-'a']++;
        }
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                 if(ch1==ch2 || frq[ch1-'a']==0 || frq[ch2-'a']==0) continue;
                 for(int i=1;i<=2;++i){
                     int cnt1=0;
                     int cnt2=0;
                     for(auto it:s){
                         if(ch1==it) cnt1++;
                         if(ch2==it) cnt2++;
                         if(cnt2>cnt1){
                              cnt1=0;
                              cnt2=0;
                            }
                     if(cnt1>0 and cnt2>0){
                          ans=max(ans,cnt1-cnt2);
                     }
                     }
                     reverse(s.begin(),s.end()); 
                 }
            }
        }
        return ans;
    }
};