#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int parent[N] , sz[N];


// THIS PART IS 'DSU' ALGORITHM

void make( int v ){

    parent[v] = v;
    sz[v] = 1;
}
int find( int v ){

    if( parent[v] == v ){
        return parent[v];
    }
    return parent[v] = find( parent[v] );
}
void Union( int a , int b ){

    a = find( a );
    b = find( b );
    if( a != b ){
        if( sz[a] < sz[b] ){
            swap( a , b );
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){

    int v , e;
    cin >> v >> e;
    vector< pair < int , pair < int , int >>> edges;
    for( int i = 0; i < e; i++ ){
        int from , to , wt;
        cin >> from >> to >> wt;
        edges.push_back({ wt , { from , to }});
    }
    sort( edges.begin() , edges.end() );
    for( int i = 1; i <= v; i++ ) make(i);

    int totalCost = 0;
    for( auto &edge : edges ){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if( find( u ) == find( v ) ) continue;
        Union( u , v );
        totalCost += wt;
        cout << u <<" "<< v << endl;
    }
    cout << totalCost << endl;

    return 0;
}