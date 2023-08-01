#include<bits/stdc++.h>
#define V 5
using namespace std;

unordered_map< int , vector< int >> adj;

void DFS( int u , vector< int > &disc , vector< int > &low , vector< int > &parent , vector<pair < int , int >> &bridge){

    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    int child = 0;

    for( int v : adj[u] ){  // Tarjan Algorithm and DFS
        if( disc[v] == -1 ){
            child += 1;
            parent[v] = u;
            DFS( v , disc , low , parent , bridge );
            low[u] = min( low[u] , low[v] );

            if( low[v] > disc[u] ) bridge.push_back({u ,v });
        }
        else if( v != parent[u] ){
            low[u] = min( low[u] , disc[v]);
        }
    }
}
void findBridges(){
    vector< int > disc(V , -1),low(V , -1),parent( V , -1 );
    vector< pair < int , int >> bridge;

    for( int i = 0; i < V; i++ ){
        if( disc[i] == -1 ){
            DFS( i , disc , low , parent , bridge);
        }
    }
    cout << "Brideges are" << endl;;
    for( auto node : bridge ){
        cout << node.first <<" ---- "<< node.second << endl;;
    }
}
int main(){

    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[1].push_back(0);
    adj[0].push_back(1);
    adj[2].push_back(1);
    adj[1].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    findBridges();

    return 0;
}