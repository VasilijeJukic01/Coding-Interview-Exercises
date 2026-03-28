class NumArray {
private:
    vector<int> tree;
    int n;

    void build(vector<int>&nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        build(nums, leftChild, start, mid);
        build(nums, rightChild, mid + 1, end);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    void update(int val, int index, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (index <= mid) {
            update(val, index, leftChild, start, mid);
        }
        else update(val, index, rightChild, mid + 1, end);
        
        tree[node] = tree[leftChild] + tree[rightChild];
    }

    int query(int node, int start, int end, int left, int right) {
        if (end < left || start > right) return 0;
        if (start >= left && end <= right) return tree[node];

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = query(leftChild, start, mid, left, right);
        int rightSum = query(rightChild, mid + 1, end, left, right);

        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        update(val, index, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */