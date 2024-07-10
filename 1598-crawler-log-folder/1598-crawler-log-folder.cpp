class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps = 0;
        for (auto log : logs)
            if (log == "../")
                steps = max(0, steps - 1);
            else if (log != "./")
                ++steps;
        return steps;
    }
};