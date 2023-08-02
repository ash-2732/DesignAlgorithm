#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    void findBiconnectedComponentsUtil(int u, int parent, vector<int>& disc, vector<int>& low, stack<pair<int, int>>& st, vector<vector<int>>& biconnectedComponents) {
        static int time = 0;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            if (disc[v] == -1) {
                children++;
                st.push({u, v});
                findBiconnectedComponentsUtil(v, u, disc, low, st, biconnectedComponents);

                low[u] = min(low[u], low[v]);

                // If u is an articulation point
                if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
                    vector<int> component;
                    while (!st.empty() && st.top() != make_pair(u, v)) {
                        component.push_back(st.top().first);
                        component.push_back(st.top().second);
                        st.pop();
                    }
                    if (!st.empty()) {
                        component.push_back(st.top().first);
                        component.push_back(st.top().second);
                        st.pop();
                    }
                    biconnectedComponents.push_back(component);
                }
            }
            else if (low[u] > disc[v]) {
                low[u] = min(low[u], disc[v]);
                st.push({u, v});
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> findBiconnectedComponents() {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        stack<pair<int, int>> st;
        vector<vector<int>> biconnectedComponents;

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                findBiconnectedComponentsUtil(i, -1, disc, low, st, biconnectedComponents);
                vector<int> component;
                while (!st.empty()) {
                    component.push_back(st.top().first);
                    component.push_back(st.top().second);
                    st.pop();
                }
                if (!component.empty()) {
                    biconnectedComponents.push_back(component);
                }
            }
        }

        return biconnectedComponents;
    }
};

int main() {
    int V, E;
    //cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    //cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<vector<int>> biconnectedComponents = g.findBiconnectedComponents();

    cout << "Biconnected Components:" << endl;
    for (const vector<int>& component : biconnectedComponents) {
        for (int i = 0; i < component.size(); i += 2) {
            cout << component[i] << " - " << component[i + 1] << "\t";
        }
        cout << endl;
    }

    return 0;
}
