class RandomizedSet {
public:
    vector<int> container;
    unordered_map<int, int> table;

    RandomizedSet() {}
    
    bool insert(int val) {
        if (table.count(val)) return false;

        container.push_back(val);
        table[val] = container.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!table.count(val)) return false;
        
        int removeIndex = table[val];
        int lastIndex = container.size() - 1;

        table[container[lastIndex]] = removeIndex;
        swap(container[removeIndex], container[lastIndex]);
        
        table.erase(val);
        container.pop_back();

        return true;
    }
    
    int getRandom() {
        int random = rand() % container.size();
        return container[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */