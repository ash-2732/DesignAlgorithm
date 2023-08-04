#include<bits/stdc++.h>
using namespace std;

int main(){

    int n , m;
    cin >> n >> m;
    vector< int > temp;
    int count = 0;
    vector<vector< int >> adj(n);
    vector< int > indeg(n , 0 );
    for( int i = 0; i < m; i++ ){
        int u , v;
        cin >> u >> v;
        // u ---> v
        adj[u].push_back(v);
        indeg[v]++;
    }
    int cnt = 0;
    queue< int > pq;
    for( int i = 0; i < n; i++ ){
        if( indeg[i] == 0 ){
           // cnt++;
           //cout << indeg[i] << endl;
            pq.push(i);
        }
    }
    //cout << "Com" << endl;
    while( !pq.empty() ){
        count++;
        int x = pq.front();
        pq.pop();
        //cout << x << endl;
        for( auto it : adj[x] ){
            //cout << it <<" "<< endl;
            temp.push_back( indeg[it] );
            indeg[it]--;
            //cout << indeg[it] <<" "<< endl;
            if( indeg[it] == 0 ){
                pq.push( it );
            }
        }
    }
    //cout << count << endl;
    // cout << cnt << endl;
    int numOfValidTopological = *max_element( temp.begin() , temp.end() );
    cout << numOfValidTopological << endl;

    return 0;
}

