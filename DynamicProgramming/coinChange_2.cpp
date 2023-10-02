#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;

int dp[310][1010];

int func( int index , int amount , vector< int > &coins ){

    if( amount == 0 ) return 1;
    if( index < 0 ) return 0;
    if( dp[index][amount] != -1 ) return dp[index][amount];

    int ways = 0;
    for( int coin_amount = 0; coin_amount <= amount; coin_amount += coins[index] ){
        ways += func( index - 1 , amount - coin_amount , coins );
    }
    return dp[index][amount] = ways;
}
int change( int amount, vector< int > &coins) {
    
    memset( dp , -1 , sizeof( dp ));
    int size = coins.size() - 1;
    return func( size , amount , coins );
}
int main(){

    int coinNum;
    cin >> coinNum;
    vector< int > coins(coinNum);
    for( int i = 0; i < coinNum; i++ ) cin >> coins[i];

    int amount;
    cin >> amount;
    int answer = change( amount , coins );
    cout << answer << endl;
}