class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        set<int> v;
        int n= nums.size();
        int a,b;
        a=b=-1;
        
        for(int i=0;i<n ;i++){
            if(nums[i] == key){
                a = max(b+1,i-k>=0?i-k:0);
                b = max(b+1,i+k);
                b=b<n?b:n-1;
 
                for(int j=a;j<=b;j++)v.insert(j);
     
            }
            
        }

        vector<int> s ;
        for(auto i:v){
            s.push_back(i);
        }
  
        return s;
    }
};