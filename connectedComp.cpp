#include<bits/stdc++.h>
using namespace std;

vector< bool > vis;
int n , m;
vector<vector< int >> adj;
vector< int > components;

int getComponents( int index ){
    if( vis[index] ) return 0;
    vis[index] = true;
    int ans = 1;
    for( auto i : adj[index] ){
        if( !vis[i] ){
            ans += getComponents(i);
            vis[i] = true;
        }
    }
    return ans;
}
int main(){

    cin >> n >> m;
    adj = vector<vector< int >> (n);
    vis = vector< bool > (n);

    for( int i = 0; i < m; i++ ){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for( int i = 0; i < n; i++ ){
        if( !vis[i] ){
            components.push_back( getComponents(i) );
        }
    }
    for( auto value : components ) cout << value <<" ";
    cout << endl;

    
    // 5 3          INPUT
    // 0 1
    // 2 3
    // 0 4

    // 3 2          OUTPUT

    return 0;
}