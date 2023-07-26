class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,h=1e7;
        int ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            double ttime=0;
            bool ok=false;
             double h1;
            for(auto x:dist){
                double t=x/(m*(1.0));
                h1=ttime+t;
                ttime+=ceil(t);  
            }
            if(h1<=hour){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};