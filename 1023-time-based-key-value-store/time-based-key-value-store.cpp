class TimeMap {
public:

    map<string,vector<pair<int,string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
        
        
    }
    
    string get(string key, int timestamp) {
        auto& pairs = store[key];
        int l = 0, r = pairs.size() - 1;
        std::string result = ""; 

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (pairs[mid].first <= timestamp) {
                result = pairs[mid].second; 
                l = mid + 1; 
            } else {
                r = mid - 1; 
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */