#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;

int dp[10010];

int func( int amount , vector< int > &coins ){

    if( amount == 0 ) return 0;
    if( dp[amount] != -1 ) return dp[amount];

    int ans = INT_MAX;
    for( auto i : coins ){
        if( amount - i >= 0 ){
            ans = min( ans + 0LL , func( amount - i , coins ) + 1LL );
        }
    }
    return dp[amount] = ans;
}
int coinChange( vector< int > &coins , int amount ){

    memset( dp , - 1 , sizeof( dp ));
    int ans = func( amount , coins );

    if( ans == INT_MAX ) return -1;
    else return ans;
}
int main(){

    int coinNum;
    cin >> coinNum;
    vector< int > coins(coinNum);
    for( int i = 0; i < coinNum; i++ ) cin >> coins[i];

    int amount;
    cin >> amount;

    auto start = high_resolution_clock::now();
    int answer = coinChange( coins , amount );
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast< nanoseconds > ( stop - start );
    
    cout << duration.count() << endl;
    cout << answer << endl;

}