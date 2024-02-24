class DSU {
public:
    unordered_map<int, int> par, sz;            // par denotes representative of a component, sz denotes size
    void init(vector<pair<int, int>>& meets) {
        par.clear(); sz.clear();
		// initially all person are set as their own parents and size of each component = 1
        for(auto& [i, j] : meets) par[i] = i, par[j] = j, sz[i] = sz[j] = 1;
    }
    int find(int x) {                          // find parent of a given member x
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    void Union(int x, int y) {                 // unions two component by size
        int xp = find(x), yp = find(y);
        if(xp == yp) return;
        if(sz[xp] > sz[yp]) par[yp] = par[xp], sz[xp] += sz[yp];
        else par[xp] = par[yp], sz[yp] += sz[xp];
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& M, int F) {
        map<int, vector<pair<int, int>>> mp;             // {time: [meetingPair]}
        unordered_set<int> secrets{0, F}, curSecrets, pars;
        DSU d;
        for(auto& m : M) 
            mp[m[2]].emplace_back(m[0], m[1]);
        
        for(auto& [t, meets] : mp) {
            curSecrets.clear();
            d.init(meets);
            for(auto& [i, j] : meets) {
                d.Union(i, j);                                  // two people meeting together are unioned into single group
                if(secrets.count(i)) curSecrets.insert(i);      // curSecret is filled with people knowing secret before time t
                if(secrets.count(j)) curSecrets.insert(j);
            }
            if(!size(curSecrets)) continue;
            pars.clear();
            for(auto person : curSecrets) 
				pars.insert(d.find(person));                    // get parents in DSU of all person who initially knew secret
			
			// if parent of a new person equals parent of person who knew secret, then add it to global set of people who know secret
            for(auto& [i, j] : meets) {
                if(pars.count(d.find(i))) secrets.insert(i);   
                if(pars.count(d.find(j))) secrets.insert(j);
            }
        }
        
        return vector<int>{ begin(secrets), end(secrets) };
    }
};