class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1=INT_MAX, min0=INT_MAX;
        for(int x: prices){
            if (x<min0) 
                min1=exchange(min0, x);
            else min1=min(min1, x);
        }
        int left=money-min0-min1;
        return (left>=0)?left:money;
    }
};