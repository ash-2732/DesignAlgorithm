#include<bits/stdc++.h>
using namespace std;

using namespace std::chrono;

int mat[100][100] , dp[100][100];

int row , column;

int exactPath( int i , int j ){

    if( i >= 0 && i < row and j >= 0 && j < column ){   // if inside array
        if( dp[i][j] != -1 ) return dp[i][j];

        int result = INT_MIN;
        result = max( result , exactPath( i + 1 , j ) + mat[i][j] );
        result = max( result , exactPath( i + 1 , j - 1 ) + mat[i][j] );
        result = max( result , exactPath( i + 1 , j + 1) + mat[i][j] );

        return dp[i][j] = result;
    }
    else return 0;
}
int main(){

    memset( dp , -1 , sizeof( dp ));
    cin >> row >> column;
    for( int i = 0; i < row; i++ ){
        for( int j = 0; j < column; j++ ){
            cin >> mat[i][j];
        }
    }
    int answer = 0;
    answer = exactPath( 0 , 0 );
    cout << "Maximum Point is : " << answer << endl;
}