class Solution {
public:
    double average(vector<int>& salary) {
        return (accumulate(salary.begin(), salary.end(), 0.) - *min_element(salary.begin(), salary.end())
            - *max_element(salary.begin(), salary.end())) / (salary.size() - 2);
        
        // int sum = 0;
        // int minSal = INT_MAX, maxSal = INT_MIN;
        // int n = salary.size();
        // for(int i =0; i < n; ++i)
        // {
        //     sum += salary[i];
        //     minSal = min(minSal, salary[i]);
        //     maxSal = max(maxSal, salary[i]);
        // }
        // sum -= (minSal + maxSal);
        // return sum/((n-2)*1.0);
    }
};