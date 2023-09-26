#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;


int rodCutting( vector< int > &prices , int n ){

    if( n <= 0 ) return 0;

    int maxRevenue = INT_MIN;
    for( int i = 0; i < n; i++ ){
        int revenue = prices[i] + rodCutting( prices , n - i - 1 );
        if( revenue > maxRevenue ){
            maxRevenue = revenue;
        }
    }
    return maxRevenue;
}
int main(){

    int howmanyPrice;
    cin >> howmanyPrice;
    vector< int > prices( howmanyPrice );
    for( int i = 0; i < howmanyPrice; i++ ) cin >> prices[i];

    int n; cin >> n;

    auto start = high_resolution_clock::now();
    int maxRevenue = rodCutting( prices , n );
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast< nanoseconds >( stop - start );
    cout << maxRevenue << endl;
    cout << "Time need to be executed " << duration.count() << endl;


    return 0;
}