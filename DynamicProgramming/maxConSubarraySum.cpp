#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;

int maximumSubarray( int element[] , int n ){

    if( n == 1 ){
        return element[0];
    }
    int m = n / 2;
    int left_max = maximumSubarray( element , m );
    int right_max = maximumSubarray( element + m , n - m );
    
    int left_sum = INT_MIN , right_sum = INT_MIN , sum = 0;
    for( int i = m; i < n; i++ ){
        sum += element[i];
        right_sum = max( right_sum , sum );
    }
    sum = 0;
    for( int i = m - 1; i >= 0; i-- ){
        sum += element[i];
        left_sum = max( left_sum , sum );
    }
    int cross_max = left_sum + right_sum;
    return max( cross_max , max( left_max , right_max ));
}
int main(){

    int n; cin >> n;
    int element[n];
    for( int i = 0; i < n; i++ ) cin >> element[i];

    cout << maximumSubarray( element , n ) << endl;
}