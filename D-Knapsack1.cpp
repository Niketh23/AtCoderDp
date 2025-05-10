#include <bits/stdc++.h>
using namespace std;

long long solve(int i, int n, int W, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if (i == n) return 0;

    if (dp[i][W] != -1) return dp[i][W];

    int notTake = solve(i + 1, n, W, arr, dp);
    int take = 0;
    if (W - arr[i][0] >= 0)
        take = arr[i][1] + solve(i + 1, n, W - arr[i][0], arr, dp);

    return dp[i][W] = max(take, notTake);
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1]; // arr[i][0] = weight, arr[i][1] = value
    }
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << solve(0, n, W, arr, dp);
    return 0;
}
