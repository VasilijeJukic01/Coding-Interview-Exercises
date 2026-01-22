class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adjList;

        for (auto word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                adjList[pattern].push_back(word);
            }
        }

        unordered_set<string> visited;
        queue<string> q;

        q.push(beginWord);
        visited.insert(beginWord);

        int t = 1;
        while(!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return t;

                for (int i = 0; i < curr.size(); i++) {
                    string pattern = curr;
                    pattern[i] = '*';
                    
                    for (auto word : adjList[pattern]) {
                        if (visited.find(word) == visited.end()) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                }
            }
            t++;
        }

        return 0;
    }
};