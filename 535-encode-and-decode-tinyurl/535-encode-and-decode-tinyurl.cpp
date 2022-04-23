class Solution {
    public:
//         unordered_map<string,string> mp;
//         int n = 0;
//         // Encodes a URL to a shortened URL.
//         string encode(string longUrl) {
//             string res = "http://tinyurl.com/" + to_string(n);
//             n++;
//             mp[res] = longUrl;
//             return res;
//         }

//         // Decodes a shortened URL to its original URL.
//         string decode(string shortUrl) {
//             return mp[shortUrl];
//         }
    //***************************************************************************************
    unordered_map<string, string>mp;
    int length = 6;
    
    string hashing(string longUrl){
        string hashCode = "";
        
        for(int i=0; i<length; i++){
            int random = rand() % 3;
            
            if(random == 0)
                hashCode += ('0' + rand() % 10);
            else if(random == 1)
                hashCode += ('a' + rand() % 26);
            else
                hashCode += ('A' + rand() % 26);
        }
        
        if(mp.find(hashCode) != mp.end())
            return hashing(longUrl);
        else {
            mp[hashCode] = longUrl;
            return hashCode;
        }
    }
    
    // Encoding
    string encode(string longUrl){
        string tinyUrl = "http://tinyurl.com/";
        string hashCode = hashing(longUrl);
        return tinyUrl + hashCode;
    }
    
    //Decoding
    string decode(string shortUrl) {
        string hashCode = shortUrl.substr(shortUrl.size() - length, length);
        return mp[hashCode];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));