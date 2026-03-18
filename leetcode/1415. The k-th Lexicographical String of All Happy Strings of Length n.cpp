class Solution {
public:
    void solve(int n, int& counter, string& curr, string& save) {
        if (curr.size() == n) {
            counter--;
            if (counter == 0) {
                save = curr;
            }
            return;
        }

        for (int i = 0; i < 3; i++) {
            char ch = 'a' + i;
            if (!curr.empty() && curr.back() == ch) continue;
            curr += ch;
            solve(n, counter, curr, save);
            if (!save.empty()) return;
            // Backtrack
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string save = "";
        solve(n, k, curr, save);
        return save;
    }
};