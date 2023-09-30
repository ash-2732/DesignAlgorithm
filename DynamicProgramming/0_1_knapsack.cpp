#include<bits/stdc++.h>
using namespace std;

int weight[105] , value[105];
int dp[105][100005];

int maxProfit( int index , int weight_left ){

    if( weight_left == 0 ) return 0;
    if( index < 0 ) return 0;
    if( dp[index][weight_left] != -1 ) return dp[index][weight_left];

    int ans = maxProfit( index - 1 , weight_left ); // if i didn't take anything
    if( weight_left - weight[index] >= 0 ){
        ans = max( ans , maxProfit( index - 1 , weight_left - weight[index] ) + value[index] );
        // if i take any
    }
    return dp[index][weight_left] = ans;
}
int main(){

    memset( dp , -1 , sizeof( dp ) );
    int n , w;
    cin >> n >> w;
    for( int i = 0; i < n; i++ ){
        cin >> weight[i] >> value[i];
    }
    cout << maxProfit( n - 1 , w );
}