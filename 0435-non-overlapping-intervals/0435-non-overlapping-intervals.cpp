class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;  // Return 0 if the intervals vector is empty
        }
        
        // Sort the intervals based on the end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int end = intervals[0][1];  // Initialize the end time with the first interval's end
        
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval's start time is less than the previous interval's end time,
            // it means there is an overlap
            if (intervals[i][0] < end) {
                count++;
            } else {
                end = intervals[i][1];  // Update the end time
            }
        }
        
        return count;
    }
};