#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;
const int N = 102 , MOD = 1e7 + 10;

int element[N];
int dp[N][N];


int main(){

    int n; cin >> n;
    for( int i = 0; i < n; i++ ) cin >> element[i];
    
    for( int l = 2; l < n; l++ ){
        for( int i = 1; i < n - l + 1; i++ ){
            int j = i + l -1;
            dp[i][j] = MOD;
            for( int k = i; k < j; k++ ){
                dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k+1][j] +
                element[i-1] * element[j] * element[k] );
            }
        }
    }
    cout << dp[1][n-1] << endl;

    return 0;
}