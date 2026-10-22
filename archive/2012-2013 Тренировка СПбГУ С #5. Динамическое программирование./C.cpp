#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    fread("knight.in");
    fwrite("knight.out");
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 5, vector<int>(m + 5, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -1)
                continue;
            dp[i + 2][j + 1] += dp[i][j] + 1;
            dp[i + 1][j + 2] += dp[i][j] + 1;
        }
    }

    cout << dp[n - 1][m - 1] + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
