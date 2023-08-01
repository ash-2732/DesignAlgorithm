#include<bits/stdc++.h>
#define V 5
using namespace std;

unordered_map< int , vector< int >> adj;

void DFS( int u , vector< int > &disc , vector< int > &low , vector< int > &parent , vector< bool > &apPoint ){

    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    int child = 0;

    for( int v : adj[u] ){
        if( disc[v] == -1 ){
            child += 1;
            parent[v] = u;
            DFS( v , disc , low , parent , apPoint );
            low[u] = min( low[u] , low[v] );

            if( parent[u] == -1 && child > 1 ){
                apPoint[u] = true;
            }
            if( parent[u] != -1 && low[v] >= disc[u] ){
                apPoint[u] = true;
            }
        }
        else if( v != parent[u] ){
            low[u] = min( low[u] , disc[v]);
        }
    }
}
void findArticulate(){
    vector< int > disc(V , -1),low(V , -1),parent( V , -1 );
    vector< bool > apPoint(V , false);

    for( int i = 0; i < V; i++ ){
        if( disc[i] == -1 ){
            DFS( i , disc , low , parent , apPoint );
        }
    }
    cout << "Articulate Points are: ";
    for( int i = 0; i < V; i++ ){
        if( apPoint[i] == true ){
            cout << i <<" ";
        }
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

    findArticulate();

    return 0;
}