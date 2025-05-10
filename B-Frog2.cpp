#include<bits/stdc++.h>
using namespace std;

int frog(int i,int n,int k,int arr[],vector<int>&dp){
  if(i>=n-1){
    return 0;
  }
  if(dp[i]!=-1) return dp[i];
  int op1 = INT_MAX;
  for(int j=i+1;j<=min(i + k, n - 1);j++){
    op1 = min(op1,abs(arr[j]-arr[i])+frog(j,n,k,arr,dp));
  }

  return dp[i] = op1;
}

int solve(int n,int arr[],int k){
  vector<int>dp(n+1,-1);
  return frog(0,n,k,arr,dp);
}


int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(n,arr,k);
    return 0;
}