class Solution {
public:
// Two pointer approach
//     Goal is to find a window of longest length which has sum equal to s - x, where s is sum of all the elements of the array.
// When such a window is found all the elements outside this window will sum to x and no of operations will be equal to their count.
// TC : O(N) | SC : O(1)
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size(), s = 0, ans = 1000000;
        
        for(int i = 0; i < n ; i++) s += nums[i];
        
        if(s < x) return -1;
        
        int st = 0, end = 0, windowSum = 0;
        
        while(end < n){            
            windowSum += nums[end];            
            while(windowSum > (s - x)){
                windowSum -= nums[st]; //Reducing window size
                st++;
            }            
            if(windowSum == s - x){
                ans = min(ans, n - (end - st + 1));
            }            
            end++;            
        }
		
        return (ans == 1000000 ? -1 : ans);
        
    }
};