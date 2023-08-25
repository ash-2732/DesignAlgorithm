#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9+10;



int dist[N][N];

int main(){
    
    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            if( i == j ) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int n , m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        int x , y , wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
        dist[y][x] = wt;
    }

    int ans = 0;
    int R; cin >> R;
    vector< int > temp;
    while( R-- ){
        int num;
        cin >> num;
        temp.push_back(num);
    }


    for( int k = 0; k < n; k++ ){
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                if( dist[i][k] != INF && dist[k][j] != INF )
                dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }


    for( int i = 0; i < temp.size()-1; i++ ){
        ans += dist[temp[i]][temp[i+1]];
    }
    cout << ans << endl;

    return 0;
}

    