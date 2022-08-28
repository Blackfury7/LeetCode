class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        travel.insert(travel.begin(), 0);
        vector<int>v(3,-1);
        long sum = 0;
        int n = travel.size();
        for(int i = 1; i < n; i++) travel[i] += travel[i-1]; // prefix sum
        for(auto &i : garbage) sum += i.size(); // total garbage
        for(int i = n -1; i >= 0; i--) { // finding last indeces of each garbage type
            string s = garbage[i];
            if(v[0] ==-1 and s.find('M') != string::npos) v[0] = i;
            if(v[1] == -1 and s.find('G') != string::npos) v[1] = i;
            if(v[2] == -1 and s.find('P') != string::npos) v[2] = i;
            if(v[0] !=-1 and v[1] != -1 and v[2] != -1)  break;
        }
        for(auto &i: v) sum += (i!=-1?travel[i]:0);

        return sum;
    }
};