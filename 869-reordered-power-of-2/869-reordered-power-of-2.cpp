class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if(s[0] == '0')continue;
            int num = stoi(s);
            //cout<<num<<"  "<<s<<endl;
            if(!(num & (num-1)))return true;
               
        }while(next_permutation(s.begin(), s.end()));
        return false;
    }
};