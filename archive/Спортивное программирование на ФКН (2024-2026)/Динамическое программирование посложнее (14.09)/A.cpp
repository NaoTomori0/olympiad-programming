#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n, 0);
    for (auto &i : a)
        cin >> i;

    for (int i = 0; i < n; i++)
        dp[i] = a[i] * n;

    for (int i = 2; i <= n; i++)
    {
        for (int l = 0; l <= n - i; l++)
        {
            int r = l + i - 1;
            int k = n - i + 1;
            int left_cup = a[l] * k + dp[l + 1], right_cup = a[r] * k + dp[l];
            dp[l] = max(left_cup, right_cup);

            // int r = l + i - 1;
            // int k = n - i + 1;

            // int left_cup = a[l] * k + dp[l + 1][r], right_cup = a[r] * k + dp[l][r - 1];
            // dp[l][r] = max(left_cup, right_cup);
        }
    }
    // for (auto &i : dp)
    // {
    //     cout << i << ' ';
    //     // cout << '\n';
    // }
    cout << dp[0];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
