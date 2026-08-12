class LRUCache {
private:
    int capacity;
    // map key -> {value, iterator to where the key lives in the list}
    unordered_map<int,pair<int, list<int>::iterator>> map;
    // doubly linked list storing keys
    list<int> dll;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        dll.erase(map[key].second);
        dll.push_back(key);
        map[key].second = --dll.end();
        return map[key].first;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) dll.erase(map[key].second);
        else if (map.size() == capacity) {
            int lru = dll.front();
            dll.pop_front();
            map.erase(lru);
        }
        dll.push_back(key);
        map[key] = {value, --dll.end()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */