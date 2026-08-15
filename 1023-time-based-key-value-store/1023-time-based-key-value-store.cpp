class TimeMap {
// hash table to store key -> vector of {timestamp, value}
unordered_map<string, vector<pair<int, string>>> hashTable;

public:
    TimeMap() {}
    // add to the hash table
    void set(string key, string value, int timestamp) {
        hashTable[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if (hashTable.find(key) == hashTable.end()) return "";

        auto& arr = hashTable[key];
        int l = 0, r = arr.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + ((r - l) / 2);
            if (arr[mid].first <= timestamp) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if (ans == -1) return "";
        else return arr[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */