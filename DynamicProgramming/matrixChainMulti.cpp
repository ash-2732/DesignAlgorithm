#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;
const int N = 102 , MOD = 1e7 + 10;

int element[N];
int dp[N][N];

 int MCM( int i , int j ){

    if( i == j ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];

    dp[i][j] = MOD;
    for( int k = i; k < j; k++ ){
        dp[i][j] = min( dp[i][j] , MCM( i , k ) + MCM( k + 1 , j ) +
        element[i-1] * element[j] * element[k] );
    }
    return dp[i][j];
}
int main(){

    memset( dp , -1 , sizeof( dp ));
    int n; cin >> n;
    for( int i = 0; i < n; i++ ) cin >> element[i];
    cout << MCM( 1 , n - 1) << endl;

    return 0;
}