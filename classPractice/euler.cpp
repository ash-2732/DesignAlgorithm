#include<bits/stdc++.h>
using namespace std;

unordered_map< int , vector< int >> adj;
int V , E;

void DFS( int curr , vector< bool > &visited ){

    visited[curr] = true;
    for( auto it : adj[curr] ){
        if( !visited[it] ){
            DFS( it , visited );
        }
    }
}
bool Connected_Graph(){

    vector< bool > visited(V+1 , false);
    int node = -1; // node to DFS
    for( int i = 0; i < V; i++ ){
        if( adj[i].size() > 0 ){
            node = i;   // found a node to start DFS
            break;
        }
    }
    if( node == -1 )  return true; // no start node was found --> no edges are present in graph and it is always eulerian
    DFS( node , visited );
    for( int i = 0; i < V; i++ ){
        if( visited[i] == false && adj[i].size() > 0 ) return false;    // we have edges in multi component
    }
    return true;

}
int find_euler(){

    if( !Connected_Graph() ) return 0;  // for multicomponent edged graph and all nonzero degree vertices should be connected

    // count odd degree vertices
    int oddDegree = 0;
    for( int i = 0; i < V; i++ ){
        if( adj[i].size() & 1 ) oddDegree += 1;
    }
    if( oddDegree > 2 ) return 0;   // only start and ending have odd degree
    return ( oddDegree == 0 ) ? 2 : 1; // 1--> semi-eulerian   2--> eulerian graph

}
void findEuler_path_cycle(){

    int ret = find_euler();
    if( ret == 0 ) cout << "Graph is not Euler" << endl;
    else if( ret == 1 ) cout << "Graph is Semi-Eulerian" << endl;
    else cout << "Graph is Eulerian(Euler circuit)" << endl;
}
int main(){

    cin >> V >> E;
    for( int i = 0; i < E; i++ ){
        int from , to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    findEuler_path_cycle();
    return 0;
}