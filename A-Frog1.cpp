#include<bits/stdc++.h>
using namespace std;

int frog(int i,int n,int arr[],vector<int>&dp){
  if(i==n-1){
    return 0;
  }
  if(dp[i]!=-1) return dp[i];
  int op1 = INT_MAX, op2 = INT_MAX;
  if(i+1<n) op1 = abs(arr[i+1]-arr[i])+frog(i+1,n,arr,dp);
  if(i+2<n) op2 = abs(arr[i+2]-arr[i])+frog(i+2,n,arr,dp);

  return dp[i] = min(op1,op2);
}

int solve(int n,int arr[]){
  vector<int>dp(n+1,-1);
  return frog(0,n,arr,dp);
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(n,arr);
    return 0;
}