#include<bits/stdc++.h>
using namespace std;

bool solve(int stone,vector<int>&stones,vector<int>&dp){
  if(stone==0) return false;

  if(dp[stone]!=-1) return dp[stone];

  for(int i=0;i<stones.size();i++){
    if(stone-stones[i]>=0 && !solve(stone-stones[i],stones,dp)){
      return dp[stone] = true;
    }
  }
  return dp[stone] = false;
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>stones(n);
  for(int i=0;i<n;i++){
    cin>>stones[i];
  }

  vector<int>dp(k+1,-1);

  if(solve(k,stones,dp)){
    cout<<"First"<<endl;
  }
  else{
    cout<<"Second"<<endl;
  }
  return 0;
}