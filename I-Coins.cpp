#include <bits/stdc++.h>
using namespace std;

double solve(int i, int j, int n, vector<double> &prob, vector<vector<double>> &dp) {
    if (i == n) {
        return (j > n / 2) ? 1.0 : 0.0;
    }

    if (dp[i][j] != -1) return dp[i][j];

    double take = prob[i] * solve(i + 1, j + 1, n, prob, dp);
    double notake = (1 - prob[i]) * solve(i + 1, j, n, prob, dp);

    return dp[i][j] = take + notake;
}

int main() {
    int n;
    cin >> n;
    vector<double> prob(n);
    for (int i = 0; i < n; i++) {
        cin >> prob[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
    cout << fixed << setprecision(10) << solve(0, 0, n, prob, dp) << endl;

    return 0;
}
