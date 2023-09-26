#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;

int rodCutting( vector< int > &prices , int n ){

    vector< int > dp( n + 1 , 0 );
    for( int i = 1; i <= n; i++ ){
        int maxRevenue = INT_MIN;

        for( int j = 0; j < i; j++ ){
            maxRevenue = max( maxRevenue , prices[j] + dp[i-j-1] );
        }
        dp[i] = maxRevenue;
    }
    return dp[n];
}
int main(){

    int howmanyPrice;
    cin >> howmanyPrice;
    vector< int > prices( howmanyPrice );
    for( int i = 0; i < howmanyPrice; i++ ) cin >> prices[i];

    int n; cin >> n;
    auto start = high_resolution_clock::now();
    int maxAns = rodCutting( prices , n );
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast< nanoseconds > ( stop - start );
    cout << maxAns << endl;
    cout << "Time need to be executed " << duration.count() << endl;

    return 0;
}