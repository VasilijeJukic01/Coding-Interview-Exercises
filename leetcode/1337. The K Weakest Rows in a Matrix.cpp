class Solution {
public:
    typedef struct row {
        int index;
        int soldiers;

        bool operator<(const row& other) const {
            return soldiers < other.soldiers || 
                (soldiers == other.soldiers && index < other.index); 
        }
    } row;

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<row> pq;

        for (int i = 0; i < mat.size(); i++) {
            int soldiers = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) soldiers++;
                else break;
            }
            row r;
            r.index = i;
            r.soldiers = soldiers;
            pq.push(r);

            if (pq.size() > k) pq.pop();
        }

        vector<int> result;
        while (!pq.empty()) {
            row r = pq.top();
            result.push_back(r.index);
            pq.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};