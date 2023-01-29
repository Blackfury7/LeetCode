class LFUCache {
    public:
    int capacity;
    unordered_map<int, pair<int,int>> cache;
    unordered_map<int, list<int>::iterator> listItrMap;
    unordered_map<int,list<int>> freqMap;
    int minFreq=0;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        
        updateFrequency(key);         
        return cache[key].first;
    }
    
    void put(int key, int value) 
    {
        if(this->capacity<=0) return;
        // if key is already in cache
        if(cache.count(key))
        {
            updateFrequency(key);            
            cache[key].first = value; //update value in cache
        }
        else
        {
            if(cache.size() >= this->capacity)
            {
                // remove last-element in the least-frequent-list, from cache
                int leastFrequentKey = freqMap[minFreq].back();
                cache.erase(leastFrequentKey);
                listItrMap.erase(leastFrequentKey);
                
                // remove least frequent from freqMap
                freqMap[minFreq].pop_back();
            } 
            
            // insert value and initialize frequency
            cache[key] = {value, 0};
            freqMap[0].push_front(key);
            listItrMap[key] = freqMap[0].begin();
            
            minFreq=0;// reset min frequency
        }
    }
    
    private:
    void updateFrequency(int key)
    {
        int freq = cache[key].second++;
        
        // remove from prev frequency list
        freqMap[freq].erase(listItrMap[key]);
        
        // append to updated frequency list
        freqMap[freq+1].push_front(key);
        
        //update list pointer to new list begin
        listItrMap[key] = freqMap[freq+1].begin();

        // remove empty lists incase minFrequency raises
         if(freqMap[minFreq].size()==0 ) 
           {
              freqMap.erase(minFreq++);
           }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */