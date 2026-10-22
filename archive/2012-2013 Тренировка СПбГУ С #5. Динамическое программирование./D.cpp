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
    fread("king2.in");
    fwrite("king2.out");
    vector<vector<int>> a(8, vector<int>(8)), dp(8, vector<int>(8, 1e18));
    for (auto &i : a)
        for (auto &j : i)
            cin >> j;
    dp[7][0] = 0;
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 7 && !j)
                continue;
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
            if (i < 7)
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + a[i][j]);
            if (i < 7 && j > 0)
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
        }
    }
    cout << dp[0][7];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
