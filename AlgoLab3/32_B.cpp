#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> graph[N];
int discovery[N], lowest[N], parent[N], timeStamp;
stack<int> S;
vector<vector<int>> biconnected;

void dfs(int u) {
  discovery[u] = lowest[u] = ++timeStamp;
  S.push(u);

  for (int v : graph[u]) {
    if (discovery[v] == 0) {
      parent[v] = u;
      dfs(v);
      lowest[u] = min(lowest[u], lowest[v]);
      if (lowest[v] >= discovery[u]) {
        vector<int> biconnectedCompo;
        int w;
        do {
          w = S.top();
          S.pop();
          biconnectedCompo.push_back(w);
        } while (w != v);
        biconnectedCompo.push_back(u);
        biconnected.push_back(biconnectedCompo);
      }
    } else if (v != parent[u]) {
      lowest[u] = min(lowest[u], discovery[v]);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (discovery[i] == 0) {
      dfs(i);
    }
  }

  sort(biconnected.begin(), biconnected.end(), [](const vector<int>& a, const vector<int>& b) {
    return a.front() < b.front();
  });

    int count = 0;
    int count2 = biconnected.size();
  for (const auto& biconnectedCompo : biconnected) {
    count++;

    vector<pair<int, int>> edges;
    for (int v : biconnectedCompo) {
       // count++;
      for (int u : graph[v]) {
        if (find(biconnectedCompo.begin(), biconnectedCompo.end(), u) != biconnectedCompo.end()) {
          edges.push_back({min(u, v), max(u, v)});
          //reverse( edges.begin() , edges.end() );
        }
      }
      
    }
    //cout << "--" << endl;
    sort( edges.begin(), edges.end() );
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

    
    
    if( edges.empty() ){
        cout << "---" << endl;
    }
    else{
        for (const auto& edge : edges) {
        //cout << "-";
            cout << edge.first << " " << edge.second << endl;
        }
        //cout << "---" << endl;
        if( count != count2 ) cout << "---" << endl;
    }
    
    //cout << "---" << endl;
    
  }

  return 0;
}
