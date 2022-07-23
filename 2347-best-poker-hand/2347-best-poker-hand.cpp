class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char,int>m;
        unordered_map<int,int>m1;
        int flag=0;
        for(auto &i:ranks){
            m1[i]++;
            if(m1[i]>=3)flag=3;
            else if(flag!=3 && m1[i]>=2)flag=2;
    }
        for(auto i:suits){
            m[i]++;
           
        }
        if(m[suits[0]] == 5)flag=1;
        string ar[] = {"High Card", "Flush", "Pair", "Three of a Kind"};
        return ar[flag];
    }
        
};