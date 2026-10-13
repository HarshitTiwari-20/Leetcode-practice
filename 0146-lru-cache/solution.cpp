
class LRUCache {
private:
    int cap;
    // you dum
    std::list<std::pair<int, int>> cacheList; 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
       
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
           
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }
      
        if (cacheList.size() >= cap) {
            int lruKey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(lruKey);
        }
        
      
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */