#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;

int rodCutting( vector< int > &prices , int n , vector< int > memo ){

    if( n <= 0 ) return 0;
    if( memo[n] != -1 ) return memo[n];
    int maxRevenue = INT_MIN;
    for( int i = 0; i < n; i++ ){
        int revenue = prices[i] + rodCutting( prices , n-i-1 , memo );
        if( revenue > maxRevenue ){
            maxRevenue = revenue;
        }
    }
    memo[n] = maxRevenue;
    return maxRevenue;
}
int main(){

    int howmanyPrices;
    cin >> howmanyPrices;
    vector< int > prices( howmanyPrices );
    for( int i = 0; i < howmanyPrices; i++ ) cin >> prices[i];

    int n; cin >> n;
    vector< int > memo( n+1 , -1 );
    
    auto start = high_resolution_clock::now();
    int maxAns = rodCutting( prices , n , memo );
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast< nanoseconds > ( stop - start );
    cout << maxAns << endl;
    cout << "Time need to be executed " << duration.count() << endl;

    return 0;
}