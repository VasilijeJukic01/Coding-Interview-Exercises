class Solution {
    char chars[4] = {'A', 'C', 'G', 'T'};
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> database;

        for (auto& gene : bank) {
            database.insert(gene);
        }

        queue<string> processing;
        processing.push(startGene);

        int steps = 0;
        while (!processing.empty()) {
            int size = processing.size();
            for (int k = 0; k < size; k++) {
                string gene = processing.front();
                if (gene == endGene) return steps;
                processing.pop();

                for (int i = 0; i < 8; i++) {
                    char ch = gene[i];
                    for (auto& next : chars) {
                        if (ch == next) continue;
                        string mutation = gene;
                        mutation[i] = next;

                        if (database.find(mutation) != database.end()) {
                            processing.push(mutation);
                            database.erase(mutation);
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};