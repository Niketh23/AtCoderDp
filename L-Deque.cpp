#include<bits/stdc++.h>
using namespace std;

long long solve(int l,int r,vector<long long>&arr,vector<vector<long long>>&dp){
  if(r<l){
    return 0;
  }
  if(dp[l][r]!=-1) return dp[l][r];

  long long op1 = arr[l] - solve(l+1,r,arr,dp);
  long long op2 = arr[r] - solve(l,r-1,arr,dp);
  return dp[l][r] = max(op1,op2);
}


int main(){
  int n;
  cin>>n;
  vector<long long>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));


  cout<<solve(0,n-1,arr,dp);
}