class Solution {
public:
     
    vector<int> z_function(string s) {
        int n = (int) s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
    long long sumScores(string s) {
        
        
        auto v = z_function(s);
        long long sum=s.length();
        sum=accumulate(v.begin(),v.end(),sum);
        // for(auto i:v)sum+=i;
        return sum;
        
        
        
        //Brute force
//         long long n=s.length();
//         long long j,i;
//         long long f=n;
//         for( i=1; i<n; i++){
     
//             for( j=i;j<n;j++){
//                 if(s[j]!=s[j-i])break;
//             }
//             f+=j-i;
//         }
//         return f; 
       
    }
};