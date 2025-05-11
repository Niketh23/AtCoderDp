#include <bits/stdc++.h>
using namespace std;

long long solve(int i, int val_left, int n,
                const vector<vector<int>>& arr,
                vector<vector<long long>>& dp) {
    if (val_left == 0) return 0;
    if (i < 0) return 1e15;  // Very large value as "infinity"

    if (dp[i][val_left] != -1) return dp[i][val_left];

    long long ans = solve(i - 1, val_left, n, arr, dp);  // Don't take
    if (val_left - arr[i][1] >= 0) {
        ans = min(ans, arr[i][0] + solve(i - 1, val_left - arr[i][1], n, arr, dp));  // Take
    }

    return dp[i][val_left] = ans;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];  // weight, value
    }

    int max_val = n * 1000;  // Max total value: n × max value per item (assumed ≤ 1000)
    vector<vector<long long>> dp(n, vector<long long>(max_val + 1, -1));

    for (int i = max_val; i >= 0; i--) {
        if (solve(n - 1, i, n, arr, dp) <= W) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
