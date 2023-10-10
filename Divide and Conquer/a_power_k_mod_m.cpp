#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int binExpoIt( int a , int k ){

    int ans = 1;
    while( k > 0 ){
        if( k & 1 ){
            ans = ( ans * 1LL * a ) % M;
        }
        a = ( a * 1LL * a ) % M;
        k >>= 1;
    }
    return ans;
}
int main(){

    int a , k;
    cin >> a >> k;
    cout << binExpoIt( a , k ) << endl;

    return 0;
}