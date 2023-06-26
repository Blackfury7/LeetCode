class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int cand) {
        long long sum=0;
        int i=0;
        int n=cost.size();
        int j=n-1;
        int a=0;
        int b=0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        while(i<j && i<cand){
            pq1.push(cost[i++]);
            pq2.push(cost[j--]);
            a++;
            b++;
        }
        if(n==2*cand-1){
            pq1.push(cost[i++]);
            a++;
        }
        while(i<=j && k--){
            if(pq1.top()<=pq2.top()){
                sum+=pq1.top();
                pq1.pop();
                pq1.push(cost[i]);
                i++;
            }
            else {
                sum+=pq2.top();
                pq2.pop();
                pq2.push(cost[j]);
                j--;
            }
        }
        while(k-->0){
            if(a>0 && b>0){
                if(pq1.top()<=pq2.top()){
                    sum+=pq1.top();
                    pq1.pop();
                    a--;
                }
                else {
                    sum+=pq2.top();
                    pq2.pop();
                    b--;
                }
            }
            else if(pq1.size()){
                sum+=pq1.top();
                pq1.pop();
                a--;
            }
            else{
                sum+=pq2.top();
                pq2.pop();
                b--;
            }
        }
        return sum;

    }
};