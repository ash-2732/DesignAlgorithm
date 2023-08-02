//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if( n == 1 ) return 1;
        if( n == 2 ) return -1;
        else{
            long long int preSum[n];
        preSum[0] = a[0];
        for( long long int i = 1; i < n; i++ ){
            preSum[i] = a[i] + preSum[i-1];
        }
        //for( int i = 0; i < n; i++ ) cout << preSum[i] <<" ";
        // Your code here
        bool ok = false;
        int index = 0;
        for( int i = n-2;i >=1; i-- ){
            if( preSum[n-1] - preSum[i] == preSum[i-1] ){
                index = i;
                ok = true;
                break;
            }
        }
        if( ok ) return index + 1;
        else return -1;
        }
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends