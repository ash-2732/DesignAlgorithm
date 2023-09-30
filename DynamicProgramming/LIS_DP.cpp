#include<bits/stdc++.h>
using namespace std;

const int N = 25e2 + 10;
vector< int > element(N);
int dp[N];

int LongestIncreasingSeq( int i ){

    if( dp[i] != -1 ) return dp[i];
    int ans = 1;
    for( int j = 0; j < i; j++ ){
        if( element[i] > element[j] ){
            ans = max( ans , LongestIncreasingSeq( j ) + 1 );
        }
    }
    return dp[i] = ans;
}
int main(){

    memset( dp , -1 , sizeof( dp ) );
    int n;
    cin >> n;
    for( int i = 0; i <= n; i++ ) cin >> element[i];

    int ans = 0;
    for( int i = 0; i < n; i++ ){
        ans = max( ans , LongestIncreasingSeq( i ) );
    }
    cout << ans << endl;

    return 0;
}