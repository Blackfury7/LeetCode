class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        
       
        int f = 0;
        int ind = 0;
        
        for(int i = 1; i < n; i++) {
            if(skills[ind] > skills[i]){
                f++;  
            }
            else{
                f = 1;
                ind = i;
            }
            if(f >= k) return ind;
            
        }
        return ind;
        
     
    }
};