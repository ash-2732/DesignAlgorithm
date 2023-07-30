#include<bits/stdc++.h>
int const N = 1e5 + 10;
using namespace std;


vector< int > g[N];
int depth[N];

void DFS( int v , int par = -1 ){
    for( auto child : g[v] ){
        if( child == par ) continue;
        depth[child] = depth[v] + 1;
        DFS( child , v );
    }
}
int main(){

    int n; cin >> n;
    for( int i = 1; i <= n; i++ ){
        int from , to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    DFS(1);
    int mx_depth = -1;
    int mx_d_node = 0;
    for( int i = 1; i <= n; i++ ){
        if( mx_depth < depth[i] ){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }
    DFS( mx_d_node );
    mx_depth = -1;
    for( int i = 1; i <= n; i++ ){
        if( mx_depth < depth[i] ){
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
    
    return 0;
}