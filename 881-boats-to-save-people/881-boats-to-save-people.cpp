class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n=people.size();
        int f=0;
        for(int i=0,j=n-1; i<=j&&i<n&&j>=0;){
            if(people[i]+people[j] <= limit){
                i++;j--;f++;
            }
            else{
                j--;f++;
            }
        }
        return f;
    }
};