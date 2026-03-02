class RandomizedCollection {
public:
    // {key, indices}
    unordered_map<int, unordered_set<int>> table;
    vector<int> data;

    RandomizedCollection() {}
    
    bool insert(int val) {
        bool exists = table[val].empty();
        table[val].insert(data.size());
        data.push_back(val);
        
        return exists;
    }
    
    bool remove(int val) {
        if (table[val].empty()) return false;
        
        int removeIndex = *table[val].begin();
        table[val].erase(removeIndex); 
        
        int lastVal = data.back();
        int lastIndex = data.size() - 1;
        data[removeIndex] = lastVal;

        table[lastVal].insert(removeIndex);
        table[lastVal].erase(lastIndex);
        
        data.pop_back();
        if (table[val].empty()) table.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int index = rand() % data.size();
        return data[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */