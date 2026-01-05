class SnapshotArray {
public:
    using p = array<int, 2>;

    // Diary -> {value, version}
    vector<vector<p>> history;
    int version = 0;

    SnapshotArray(int length) {
        history.resize(length, {});
        for (int i = 0; i < length; i++) {
            history[i].push_back({0, version});
        }
    }
    
    void set(int index, int val) {
        if (history[index].back()[1] == version) {
            history[index].back()[0] = val;
        }
        else {
            history[index].push_back({val, version});
        }
    }
    
    int snap() {
        version++;
        return version - 1;
    }
    
    int get(int index, int snap_id) {
        int start = 0;
        int end = history[index].size() - 1;

        int mostRecent = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (history[index][mid][1] == snap_id) {
                return history[index][mid][0];
            }
            else if (snap_id > history[index][mid][1]) {
                mostRecent = history[index][mid][0];
                start = mid + 1;
            }
            else end = mid - 1;
        }

        return mostRecent;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */