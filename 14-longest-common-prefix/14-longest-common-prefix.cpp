class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string tmp, tmp1=strs[0];
        int n = strs.size();
        for(int i =1;i<n; i++){
            int j=0,z=0; tmp="";
            while(j<tmp1.length() && z < strs[i].length()){
                if(tmp1[j] != strs[i][z])break;
                tmp += tmp1[j];
                j++;z++;
            }
            if(tmp.length() < tmp1.length())tmp1 = tmp;
        }
        return tmp1;
    }
};