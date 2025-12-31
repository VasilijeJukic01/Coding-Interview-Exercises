class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;
        for (int i = 0; i < folder.size(); i++) {
            if (result.empty() || folder[i].find(result.back() + '/') != 0) {
                result.push_back(folder[i]);
            }
        }
        
        return result;
    }
};