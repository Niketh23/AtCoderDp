#include <bits/stdc++.h>
using namespace std;

long long solve(int l, int r, vector<long long>& arr, vector<vector<long long>>& dp) {
    if (l == r) return 0;
    if (r < l) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    long long ans = LLONG_MAX;
    for (int k = l; k < r; k++) {
        long long cost = arr[r] - (l > 0 ? arr[l - 1] : 0);
        ans = min(ans, solve(l, k, arr, dp) + solve(k + 1, r, arr, dp) + cost);
    }

    return dp[l][r] = ans;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Prefix sum
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, -1));

    cout << solve(0, n - 1, arr, dp) << endl;

    return 0;
}
