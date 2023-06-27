class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,pair<int,int>>> pq; //inserting the pair of sum and pair of u and v in a pq 
        for(int &x: nums1){
            for(int &y: nums2){
                int sum = x+y; // calculate the sum

                if(pq.size()<k) pq.push({sum,{x,y}});   //we need a k sized max-pq so insert untill size is < k

                else if(sum < pq.top().first)       //if sum of the top element in pq is greater than the next sum in line pop and insert new one
                {   
                    pq.pop();
                    pq.push({sum,{x,y}});
                }
                
                else break;         // if sum > pq.top().first as it is in ascending order it means the sums to come will be greater than curr sum
            }
        }

        while(!pq.empty())
        {
            res.push_back({pq.top().second.first,pq.top().second.second});      // storing the nums1,nums2 element pairs in vector of vector and popping
            pq.pop();
        }

        return res;
    }
};