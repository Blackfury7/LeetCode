class Solution {
public:
    int digi(int n){
        int s=0;
        while(n>0){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        
        map<int,vector<int>>m;
        for(auto i:nums){
            int x= digi(i);
            m[x].push_back(i);
        }
        int flag =1,mx=-1;
        for(auto i:m){
            auto x = i.second;
            int n_x = x.size();
            if(n_x >1){
                sort(x.begin(), x.end());
                int sum = x[n_x - 1] + x[n_x - 2];
                if(flag){
                    mx = sum;
                    flag = 0;
                }
                else{
                    if(mx < sum){
                        mx = sum;
                    }
                }
            }
        }
        return mx;
    }
};