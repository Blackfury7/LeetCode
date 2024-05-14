class NumArray {
public:
    
    // Implemented Binary Index Tree or Fenwick Tree 
     const int N = 1e5 + 10;
    int arr[100005];
    int bit[100005];
    NumArray(vector<int>& nums) {
        int n = nums.size();
        memset(arr, 0, sizeof arr);
        memset(bit, 0, sizeof bit);
        for(int i = 0; i < n; i++){
            update(i, nums[i]);
            arr[i] = nums[i];
        }
    
    }
    
    void update(int i, int x) {
        i+=1;
        int copy_x = x;
        x -= arr[i-1];
        arr[i-1] = copy_x;
        for(;i < N-10; i+=(i & -i)) {
            bit[i] += x;
        }
    }
    
    int sum(int i) {
        int ans = 0;
        for(; i > 0; i-=(i & -i))
            ans += bit[i];
        return ans;
    }
    int sumRange(int left, int right) {
        left+=1; right+=1;
        return sum(right) - sum(left-1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */