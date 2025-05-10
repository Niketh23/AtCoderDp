#include<bits/stdc++.h>
using namespace std;

int solve(int i,int prevInd,int n,vector<vector<int>>&arr,vector<vector<int>>&dp){
  if(i>=n){
    return 0;
  }
  if(dp[i][prevInd+1]!=-1) return dp[i][prevInd+1];
  int maxi = INT_MIN;
  for(int j=0;j<3;j++){
    if(j!=prevInd){
      maxi = max(maxi,arr[i][j]+solve(i+1,j,n,arr,dp));
    }
  }
  return dp[i][prevInd+1] = maxi;
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // dp[i][prevInd + 1], where prevInd ∈ {-1, 0, 1, 2}
    vector<vector<int>> dp(n, vector<int>(4, -1));

    cout << solve(0, -1, n, arr, dp) << endl;

    return 0;
}