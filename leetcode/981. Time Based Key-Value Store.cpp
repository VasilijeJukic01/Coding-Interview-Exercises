class TimeMap {
public:
    using p = pair<string, int>;

    unordered_map<string, vector<p>> map;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (map.count(key) == 0) return "";
        auto& entries = map[key];

        int start = 0;
        int end = entries.size() - 1;

        string best = "";
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (timestamp < entries[mid].second) {
                end = mid - 1;
            }
            else {
                best = entries[mid].first;
                start = mid + 1;
            }
        }

        return best;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */