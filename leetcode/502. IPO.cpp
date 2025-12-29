class Solution {
public:
    // {capital, profits}
    using p = array<int, 2>;

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> available;
        vector<p> projects;

        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        int earned = w;
        int index = 0;
        for (int i = 0; i < k; i++) {
            while (index < projects.size()) {
                if (projects[index][0] <= earned) {
                    available.push(projects[index][1]);
                    index++;
                }
                else break;
            }
            
            if (available.empty()) break;

            int profit = available.top();
            available.pop();

            earned += profit;
        }

        return earned;
    }
};