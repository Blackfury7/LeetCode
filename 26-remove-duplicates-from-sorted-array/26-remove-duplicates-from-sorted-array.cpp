class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int f=0;
        auto start = nums.begin();
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]){nums[i-1]=101;f++;}
        }
        int j =0;
        for(int i=n-1; i>=0; i--){
            if(nums[i] == 101)
            {
                nums.erase(start+i);
            }
        }
        cout<<endl;
        return n - f;
    }
};