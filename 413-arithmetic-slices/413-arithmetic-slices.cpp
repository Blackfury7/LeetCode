class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
       int f=0;int flag=1;
        for(int i=3;i<=n;i++){
            for(int j=0; j<=n-i; j++){
                flag=1; int diff=3000;
                for(int k=j;k<j+i-1;k++){
                    if(diff==3000)diff=nums[k]-nums[k+1];
                    else
                    {
                        if(diff!=nums[k]-nums[k+1]){flag=0;break;}
                    }
                    // cout<<nums[k]<<"\t";
                }
                
                if(flag)f++;
                // cout<<endl;
                
            }
        }
        return f;
    }
};