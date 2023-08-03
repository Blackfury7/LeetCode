class Solution {
public:
    map<char, string> mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

    vector<string> f(string& digits, int index){
        if(index==0){
            vector<string> ans;
            ans.clear();

            for(int i=0;i<mapping[digits[index]].size();i++){
                string s(1,mapping[digits[index]][i]);
                ans.push_back(s);
            }

            return ans;
        }

        vector<string> temp=f(digits,index-1);

        vector<string> ans;
        ans.clear();

        for(int i=0;i<temp.size();i++){
            for(int j=0;j<mapping[digits[index]].size();j++){
                string s=temp[i];

                ans.push_back(s+mapping[digits[index]][j]);
            }
        }

        return ans;
    }

    vector<string> letterCombinations(string digits) {
        if(digits==""){return {};}

        return f(digits,digits.size()-1);       
    }
};