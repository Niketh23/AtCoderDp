#include <bits/stdc++.h>
using namespace std;

int solve(int i,int n,vector<int>adj[],vector<int> &dp) {
  if(dp[i]!=-1) return dp[i];
    int maxi = 0;
    for(auto x:adj[i]){
        maxi = max(maxi,1+solve(x,n,adj,dp));
    }
    return dp[i]=maxi;
}

void addEdge(vector<int>adj[],int a,int b){
  adj[a].push_back(b);
}

int main() {
  int n,m;
  cin>>n>>m;
  vector<int>adj[n+1];
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    addEdge(adj,a,b);
  }
  vector<int> dp(n + 1, -1);
  int maxi = 0;

  for(int i=1;i<=n;i++){
      maxi = max(maxi,solve(i,n,adj,dp));
  }
  cout<<maxi<<endl;


  return 0;
}
