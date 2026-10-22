#include <bits/stdc++.h>
using namespace std;

#define int long long

// void solve()
// {
//     vector<vector<int>> dp(34, vector<int>(10, 0));

//     dp[33][0] = 1;

//     for (int i = 33; i >= 12; i--)
//     {
//         for (int j = 0; j < 9; j++)
//             if (dp[i][j] == 0)
//                 continue;

//         if (i - 3 >= 12)
//             dp[i - 3][j + 1] += dp[i][j];

//         if (i - 1 >= 12)
//             dp[i - 1][j + 1] += dp[i][j];

//         if (i % 2 == 0 && i / 2 >= 12)
//             dp[i / 2][j + 1] += dp[i][j];
//     }

//     cout << dp[12][9] << '\n';
// }

void solve()
{
    vector<vector<int>> dp(2 << 9, vector<int>(9, 0));

    dp[2][0] = 1;

    for (int i = 2; i < 2 << 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // if (dp[i][j] == 0)
            //     continue;

            if (i + 1 < (2 << 9))
                dp[i + 1][j + 1] += dp[i][j];

            if (i + 4 < (2 << 9))
                dp[i + 4][j + 1] += dp[i][j];

            if (i * 2 == 0 < (2 << 9))
                dp[i * 2][j + 1] += dp[i][j];
        }
    }
    int res = 0;
    for (auto &i : dp)
        res = max(res, i[8]);
    cout << res << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
