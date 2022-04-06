class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
     //************************************************************************************************************   
        int n = size(arr), ans = 0, mod = 1000000007;
        sort(begin(arr), end(arr));
        for(int i = 0; i < n - 2; i++){
            int T = target - arr[i],  j = i + 1, k = n - 1;
            while(j < k){
                if(arr[j] + arr[k] == T){
                    if(arr[j] == arr[k]){
                        ans = (ans + (((k - j) * (k - j + 1)) >> 1) % mod) % mod;  break;
                    } 
                    else{
                        int l = 1, r = 1;
                        while(j + 1 < k && arr[j] == arr[j + 1]) j++, l++;
                        while(k - 1 >= j && arr[k] == arr[k - 1]) k--, r++;
                        ans += (l * r) % mod;
                        j++, k--;
                    }                    
                }
                else if(arr[j] + arr[k] < T) j++;
                else k--;
            }
        }
        return ans;
        
     //************************************************************************************************************   
        // unordered_map<int,int>m;
        // int res = 0, mod = 1e9 + 7;
        // for (int i = 0; i<arr.size(); i++) {
        //     res = (res + m[target - arr[i]]) % mod;
        //     for(int j=0; j<i; j++) {
        //         m[arr[i] + arr[j]]++;
        //     }
        // }
        // return res;
     //************************************************************************************************************   
    }
};