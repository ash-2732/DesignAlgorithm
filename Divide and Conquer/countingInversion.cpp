#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


long long merge( int element[] , int l , int mid , int r ){

    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1] , b[n2];
    for( int i = 0; i < n1; i++ ) a[i] = element[l+i];
    for( int i = 0; i < n2; i++ ) b[i] = element[mid+i+1];

    int i = 0 , j = 0 , k = l;
    while( i < n1 && j < n2 ){
        if( a[i] <= b[j] ){
            element[k] = a[i];
            k++; i++;
        }
        else{
            element[k] = b[j];
            inv += n1 - i;
            k++; j++;
        }
    }
    // connect the other remain elements
    while( i < n1 ){
        element[k] = a[i];
        k++; i++;
    }
    while( j < n2 ){
        element[k] = a[j];
        k++; j++;
    }
    return inv;
}

long long mergeSort( int element[] , int l , int r ){

    long long inv = 0;
    if( r > l ){
        int mid = ( l + r ) / 2;
        inv += mergeSort( element , l , mid );
        inv += mergeSort( element , mid + 1 , r );
        inv += merge( element , l , mid , r );
    }
    return inv;
}
int main(){

    int n; cin >> n;
    int element[n];
    for( int i = 0; i < n; i++ ) cin >> element[i];

    auto start = high_resolution_clock::now();
    long long ans = mergeSort( element , 0 , n - 1 );
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast< nanoseconds > ( stop - start );
    cout << duration.count() << endl;
    cout << ans << endl;

    return 0;
}