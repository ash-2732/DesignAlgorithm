#include<bits/stdc++.h>
using namespace std;


int lower_bound( vector< int > &element , int N , int found ){

    int lo = 0 , hi = N;
    while( hi > lo ){
        int mid = ( hi + lo ) / 2;
        if( element[mid] < found ) lo = mid + 1;
        else hi = mid;
    }
    if( lo < N && element[lo] < found ) lo++;
    return lo;
}

int LenghtOfLIS( vector< int > &element ){

    int n = element.size();
    vector< int > ans;
    ans.push_back( element[0] );
    for( int i = 0; i < n; i++ ){
        if( element[i] > ans.back() ){
            ans.push_back( element[i] );
        }
        else{
            int low = lower_bound( ans , ans.size() , i );
            ans[low] = element[i];
        }
    }
    return ans.size();
}
int main(){

    int n;
    cin >> n;
    vector< int > element(n);
    for( int i = 0; i < n; i++ ) cin >> element[i];

    int ans = LenghtOfLIS( element );
    cout << ans << endl;

    return 0;

}