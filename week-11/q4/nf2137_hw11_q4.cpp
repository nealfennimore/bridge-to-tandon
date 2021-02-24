#include <iostream>
using namespace std;

int cost(int arr[], int i, int dp[]) {
    if ( i == 0 ) {
        return dp[i]=arr[i];
    }
    if ( i == 1 ) {
        return dp[i]=arr[i];
    }
    if( dp[i] != -1) {
        return dp[i];
    }
    return dp[i]=( min( cost(arr,i-1,dp), cost(arr,i-2,dp) ) + arr[i] );
}

int main() {
    int n;
    cout << "Enter board length: " << endl;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter slot " << i << endl;
        cin>>arr[i];
    }
    int dp[n];
    for(int i = 0; i < n; i++) {
        dp[i]=-1;
    }
    int i = n - 1;
    int price = cost(arr, i, dp);
    cout << "Lowest cost of a game board is " << price << endl;
    return 0;
}