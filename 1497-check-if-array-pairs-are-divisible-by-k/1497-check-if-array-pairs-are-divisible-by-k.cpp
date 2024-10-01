class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()&1) return false;
        unordered_map<int,int>m;
        for(auto x:arr) m[(x%k + k)%k]++; 
        for(auto x:arr)
        {
            int rem=(x%k + k)%k;
            if(rem==0)                        
            { 
                if(m[rem] & 1) return false;          
            }         
            else if(m[rem] != m[k - rem]) return false;   
        }
        return true;
    }
};