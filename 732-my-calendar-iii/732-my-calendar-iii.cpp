class MyCalendarThree {
    private:
    map<int,int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
      
        mp[start]++;
        mp[end]--;
        
        int maxoverlaps = 0;
        int sum = 0;
        for(auto &it:mp)
        {
            sum+=it.second;
            maxoverlaps = max(maxoverlaps , sum);
        }
        
        return maxoverlaps;
        
    }
};


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */