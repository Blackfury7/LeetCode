class Solution {
public:
    string longestPalindrome(string s) {

            int n=s.size();
            int res=1, start=0;
            string ans;

            for(int i=0; i<n; i++)
            {
                int l=i-1;
                int r=i+1;

                while(l>=0 && s[i]==s[l])
                {
                    l--;
                }
                while(r<n && s[i]==s[r])
                {
                    r++;
                }
                while(l>=0 && r<n && s[l]==s[r])
                {
                    l--;
                    r++;
                }
                int length=(r-1)-(l+1)+1;  
                if(length>res)
                {
                    res=length;
                    start=l+1;
                }
            }
            ans=s.substr(start,res);
            return ans;
    }
};