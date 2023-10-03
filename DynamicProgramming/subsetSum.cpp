#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;

int dp[205][20005];

bool func( int i , int sum , vector< int > &nums ){

    if( sum == 0 ) return true;
    if( i < 0 ) return false;
    if( dp[i][sum] != - 1 ) return dp[i][sum];

    bool isPossible = func( i - 1 , sum , nums );
    if( sum - nums[i] >= 0 ){
        isPossible |= func( i - 1 , sum - nums[i] , nums );
    }
    return dp[i][sum] = isPossible;
}

bool canPartition( vector< int >&nums ) {

    memset( dp , -1 , sizeof( dp ));
    int sum = 0;
    int sz = nums.size();
    for( int i = 0; i < sz; i++ ) sum += nums[i];
    if( sum & 1 ) return false;
    sum = sum / 2;
    return func( sz - 1 , sum , nums );
    
}
int main(){

    int num;
    cin >> num;
    vector< int > element( num );
    for( int i = 0; i < num; i++ ) cin >> element[i];
    cout << canPartition( element ) << endl;

}