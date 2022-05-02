class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n),o;
        
        int i,j;i=j=0;
        for(auto &x: nums){
            if(x&1){
                o.push_back(x);
                j++;
            }else {
                v[i]=x;
                i++;
            }
            
        }
        int k=0;
        for(int x=i;x<n;x++){
            v[x] = o[k];
            k++;
        }
        return v;
    }
};