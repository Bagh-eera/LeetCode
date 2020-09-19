
class LRUCache {
public:
    list<int> lru;
    map<int, pair<int, list<int>::iterator> > theMap;
    int max_capacity;
    
    LRUCache(int capacity) {
        max_capacity = capacity;
        lru.clear();
        theMap.clear();
    }
    
    int get(int key) {
        int res;
        if( theMap.find(key) == theMap.end())
            return -1;
        else{
            // Move the kv pair to the beginning of LRU list
            put(key, theMap[key].first);
            res = theMap[key].first;
        }
        return res;
    }
    
    void put(int key, int value) {
        if(theMap.find(key) != theMap.end()){
            //list erase function -->  <list_name>.erase(<list iterator at position>)
            lru.erase( theMap[key].second);
            // lru.push_front(key);
        }
        else if(lru.size() == max_capacity){
            theMap.erase(lru.back());
            lru.pop_back();
        }
        // Add element into LRU
        lru.push_front(key);
        // Add corresponding entry in hashtable
        
        pair<int, list<int>::iterator> new_entry;
        new_entry.first = value;
        new_entry.second = lru.begin();
        theMap[key] = new_entry;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
