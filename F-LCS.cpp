#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);
    else
        return dp[i][j] = max(solve(i - 1, j, s, t, dp), solve(i, j - 1, s, t, dp));
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();

    // 1-based indexing
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int len = solve(n, m, s, t, dp);

    string ans(len, '$');
    int i = n, j = m, index = len - 1;

    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans[index--] = s[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << ans << endl;
    return 0;
}
