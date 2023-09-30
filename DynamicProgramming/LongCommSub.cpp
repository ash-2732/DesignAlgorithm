#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int longestCommonSub( int i , int j , string &s1 , string &s2 ){

    if( i < 0 || j < 0 ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];
    int ans = longestCommonSub( i - 1 , j , s1 , s2 );
    ans = max( ans , longestCommonSub( i , j - 1 , s1 , s2 ));
    ans = max( ans , longestCommonSub( i - 1 , j - 1 , s1 , s2 ) + ( s1[i] == s2[j]));
    return dp[i][j] = ans;
}
int main(){

    memset( dp , -1 , sizeof( dp ));
    string s1 , s2;
    cin >> s1 >> s2;
    int sz1 = s1.size() , sz2 = s2.size();
    cout << longestCommonSub( sz1 - 1 , sz2 - 1 , s1 , s2 );

}