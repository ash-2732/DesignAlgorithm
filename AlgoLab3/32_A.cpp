#include<bits/stdc++.h>
//#define V 5
using namespace std;

unordered_map< int , vector< int >> adj;

int V , E;
vector< pair < int , int >> temp;
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
       // cout << node.first <<" ---- "<< node.second << endl;
        temp.push_back({ node.first , node.second });

    }
    sort( temp.begin() , temp.end() );
    for( auto va : temp ){
        cout << va.first <<" --- "<< va.second << endl;
    }
}
int main(){

    

    cin >> V >> E;
    for( int i = 0; i < E; i++ ){
        int from , to;
        cin >> from >> to;
        adj[from].push_back( to );
        adj[to].push_back( from );
    }


    findBridges();

    return 0;
}

// Complexity O( V + E )