#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector< int > adj[N];
int dfn[N], low[N], parent[N], timeStamp;
stack< int > S;
vector< vector<int>> components;

void dfs(int u) {
  dfn[u] = low[u] = ++timeStamp;
  S.push(u);

  for ( int v : adj[u] ) {
    if ( dfn[v] == 0 ) {
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if ( low[v] >= dfn[u] ) {
        vector< int > component;
        int w;
        do {
          w = S.top();
          S.pop();
          component.push_back(w);
        } while (w != v);
        component.push_back(u);
        components.push_back(component);
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
  cin >> n >> m;
  for ( int i = 0; i < m; i++ ) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (dfn[i] == 0) {
      dfs(i);
    }
  }
  for (const auto& component : components) {
    for (int v : component) {
      cout << v << " ";
    }
    cout << endl;
  }

  return 0;
}
