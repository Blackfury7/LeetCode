class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    int t[2001][2001];
    bool solve(vector<int>& stones,int curr_idx,int prev_jump){
        if(curr_idx==n-1){
            return true;
        }
        if(t[curr_idx][prev_jump]!=-1){
            return t[curr_idx][prev_jump];
        }
        bool result=false;
        for(int next_jump=prev_jump-1;next_jump<=prev_jump+1;next_jump++){
            if(next_jump>0){
                int next_stone=stones[curr_idx]+next_jump;
                if(mp.find(next_stone)!=mp.end()){
                    result=result||solve(stones,mp[next_stone],next_jump);
                }
            }
        }
        return t[curr_idx][prev_jump]=result;
    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        memset(t,-1,sizeof(t));
        return solve(stones,0,0);//stones,index,previous jump;
    }
};