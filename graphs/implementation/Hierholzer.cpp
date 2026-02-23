/*
* Hierholzer's Algorithm
 *
 * Logic:
 * - Finds an Eulerian Circuit (or Path) in a directed graph.
 * - Works by traversing edges and removing them, maintaining a stack of visited nodes.
 * - When a node has no stuck edges, add it to the path (backtracking).
 *
 * Requirements:
 * - In-degree must equal Out-degree for all nodes (Circuit).
 * - Or start/end nodes differ by 1 (Path).
 *
 * Time Complexity: O(E)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> findEulerianPath(vector<vector<int>>& graph) {
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < graph.size(); i++) {
        adj[graph[i][0]].push_back(graph[i][1]);
    }

    vector<int> path;
    stack<int> st;

    // Start from node present in the graph
    st.push(graph[0][0]);
    while (!st.empty()) {
        int curr = st.top();

        if (!adj[curr].empty()) {
            int neighbor = adj[curr].back();
            // Remove edge
            adj[curr].pop_back();
            st.push(neighbor);
        }
        else {
            // No neighbors left, Backtrack
            path.push_back(curr);
            st.pop();
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Edges: 1->2, 2->1, 1->3, 3->2, 2->4, 4->1
    vector<vector<int>> graph = {
        {1, 2}, {2, 1}, {1, 3},
        {3, 2}, {2, 4}, {4, 1}
    };

    vector<int> path = findEulerianPath(graph);

    cout << "Eulerian Circuit: ";
    for (int node : path) cout << node << " ";
    cout << endl;

    return 0;
}