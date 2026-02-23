/*
* Tarjan's Algorithm for Strongly Connected Components (SCC)
 *
 * Logic:
 * - Uses DFS traversal.
 * - Maintains discovery times (disc) and low-link values (low).
 * - Uses a stack to keep track of nodes in the current DFS path.
 * - If low[u] == disc[u], u is the head of an SCC.
 *
 * Time Complexity: O(V + E)
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Tarjan {
    int n;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> stackMember;
    stack<int> st;
    int timer;

    void SCCUtil(int u) {
        disc[u] = low[u] = ++timer;
        st.push(u);
        stackMember[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                SCCUtil(v);
                low[u] = min(low[u], low[v]);
            }
            else if (stackMember[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // Head node found, pop the stack
        if (low[u] == disc[u]) {
            while (true) {
                int v = st.top();
                st.pop();
                stackMember[v] = false;
                cout << v << " ";
                if (u == v) break;
            }
            cout << endl;
        }
    }

public:
    Tarjan(int vertices) : n(vertices), adj(vertices) {
        disc.assign(n, -1);
        low.assign(n, -1);
        stackMember.assign(n, false);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void findSCCs() {
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) SCCUtil(i);
        }
    }
};

int main() {
    Tarjan g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Strongly Connected Components:\n";
    g.findSCCs();

    return 0;
}