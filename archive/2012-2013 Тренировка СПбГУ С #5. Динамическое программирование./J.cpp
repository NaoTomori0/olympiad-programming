#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 1;
        return;
    }
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] += dp[i - 1][0] + dp[i - 1][2];
        dp[i][1] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][2] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    }

    cout << dp[n][0] + dp[n][1] + dp[n][2];
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
