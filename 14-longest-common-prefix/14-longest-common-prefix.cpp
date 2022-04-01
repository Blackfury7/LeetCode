class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string tmp, tmp1=strs[0];
        // int n = strs.size();
        // for(int i =1;i<n; i++){
        //     int j=0,z=0; tmp="";
        //     while(j<tmp1.length() && z < strs[i].length()){
        //         if(tmp1[j] != strs[i][z])break;
        //         tmp += tmp1[j];
        //         j++;z++;
        //     }
        //     if(tmp.length() < tmp1.length())tmp1 = tmp;
        // }
        // return tmp1;
        
        
        
        int n = strs.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(strs), end(strs));
        string a = strs[0];
        string b = strs[n-1];
        
        for(int i=0; i<a.size() && i<b.size(); i++){
            if(a[i]!=b[i])break;
                ans = ans + a[i];
            
        }
        
        return ans;
    }
};